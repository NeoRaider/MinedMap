/*
  Copyright (c) 2015, Matthias Schiffer <mschiffer@universe-factory.net>
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


#pragma once


#include "Block.hpp"
#include "../Buffer.hpp"
#include "../UniqueCPtr.hpp"
#include "../NBT/CompoundTag.hpp"
#include "../NBT/ListTag.hpp"

#include <cstdint>
#include <tuple>


namespace MinedMap {
namespace World {

class Chunk : public std::shared_ptr<const NBT::CompoundTag> {
public:
	static const size_t SIZE = 16;

	struct Blocks {
		Block blocks[SIZE][SIZE];
	};

private:
	static size_t getIndex(size_t x, size_t y, size_t z) {
		if (x >= SIZE || y >= SIZE || z >= SIZE)
			throw std::range_error("Chunk::getIndex(): bad coordinates");

		return 256*y + 16*z + x;
	}

	size_t len;
	UniqueCPtr<uint8_t[]> data;

	std::shared_ptr<const NBT::CompoundTag> level;
	std::shared_ptr<const NBT::ListTag<NBT::CompoundTag>> sections;

	unsigned maxY;

	void inflateChunk(Buffer buffer);
	void parseChunk();
	void analyzeChunk();

	uint8_t getBlockAt(const std::shared_ptr<const NBT::CompoundTag> &section, size_t x, size_t y, size_t z) const;
	uint8_t getDataAt(const std::shared_ptr<const NBT::CompoundTag> &section, size_t x, size_t y, size_t z) const;

public:
	Chunk(Buffer buffer);

	const NBT::ListTag<NBT::CompoundTag> & getSections() const {
		return *sections;
	}

	Blocks getTopLayer() const;
};

}
}
