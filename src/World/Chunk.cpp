/*
  Copyright (c) 2015-2018, Matthias Schiffer <mschiffer@universe-factory.net>
  Copyright (c) 2019, Roman Shishkin <spark@uwtech.org>
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include "Chunk.hpp"
#include "../NBT/ListTag.hpp"
#include "../NBT/StringTag.hpp"

#include <cstring>
#include <stdexcept>


namespace MinedMap {
namespace World {

Chunk::Chunk(const ChunkData *data) {
	level = assertValue(data->getRoot().get<NBT::CompoundTag>("Level"));

	std::shared_ptr<const NBT::ListTag> sectionsTag = level->get<NBT::ListTag>("Sections");
	if (!sectionsTag)
		return;

	biomeBytes = level->get<NBT::ByteArrayTag>("Biomes");
	biomeInts = level->get<NBT::IntArrayTag>("Biomes");
	assertValue(biomeBytes || biomeInts);

	if (biomeBytes && biomeBytes->getLength() != SIZE*SIZE)
		throw std::invalid_argument("corrupt biome data");
	else if (biomeInts && biomeInts->getLength() != SIZE*SIZE)
		throw std::invalid_argument("corrupt biome data");

	for (auto &sTag : *sectionsTag) {
		auto s = std::dynamic_pointer_cast<const NBT::CompoundTag>(sTag);
		std::unique_ptr<Section> section = Section::makeSection(s);
		if (section != nullptr) {
            size_t Y = section->getY();
            sections.resize(Y);
            sections.push_back(std::move(section));
		}
	}
}

bool Chunk::getBlock(Block *block, const Section *section, size_t x, size_t y, size_t z, uint8_t prev_light) const {
	if (block->height > 0)
		return false;

	const Resource::BlockType *type = section->getBlockStateAt(x, y, z);
	if (!type || !type->opaque)
		return false;

	if (!block->type) {
		block->type = type;
		block->blockLight = prev_light;
		block->biome = getBiomeAt(x, z);
	}

	if (type->blue)
		return false;

	block->height = SIZE*section->getY() + y;

	return true;
}

Chunk::Blocks Chunk::getTopLayer() const {
	size_t done = 0;
	Blocks ret = {};
	uint8_t prev_light[SIZE][SIZE] = {};

	for (ssize_t Y = sections.size() - 1; Y >= 0; Y--) {
		if (done == SIZE*SIZE)
			break;

		if (!sections[Y]) {
			std::memset(prev_light, 0, sizeof(prev_light));
			continue;
		}

		const Section *section = sections[Y].get();

		for (ssize_t y = SIZE-1; y >= 0; y--) {
			if (done == SIZE*SIZE)
				break;

			for (size_t z = 0; z < SIZE; z++) {
				for (size_t x = 0; x < SIZE; x++) {
					if (getBlock(&ret.blocks[x][z], section, x, y, z, prev_light[x][z]))
						done++;

					prev_light[x][z] = section->getBlockLightAt(x, y, z);
				}
			}
		}
	}

	return ret;
}

}
}
