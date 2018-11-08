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


#include "Biome.hpp"


namespace MinedMap {
namespace Resource {

const Biome BIOMES[256] = {
	/* 0 */ {0.25, 1, 0.25},
	/* 1 */ {0.3, 1, 0.3},
	/* 2 */ {1, 1, 0.25},
	/* 3 */ {0.3, 0.9, 0.3},
	/* 4 */ {0.15, 0.75, 0.15},
	/* 5 */ {0.5, 0.75, 0.5},
	/* 6 */ {0.75, 1, 0.25},
	/* 7 */ {0.25, 1, 0.25},
	/* 8 */ {1, 0.1, 0.1},
	/* 9 */ {1.5, 1.5, 0.75},
	/* 10 */ {0.25, 1, 0.25},
	/* 11 */ {0.25, 1, 0.25},
	/* 12 */ {0.3, 1, 0.3},
	/* 13 */ {0.3, 0.9, 0.3},
	/* 14 */ {0.75, 0.1, 0.75},
	/* 15 */ {0.75, 0.1, 0.75},
	/* 16 */ {1, 1, 0.25},
	/* 17 */ {1, 1, 0.25},
	/* 18 */ {0.15, 0.75, 0.15},
	/* 19 */ {0.5, 0.75, 0.5},
	/* 20 */ {0.3, 0.9, 0.3},
	/* 21 */ {0.1, 1.25, 0.1},
	/* 22 */ {0.1, 1.25, 0.1},
	/* 23 */ {0.1, 1.25, 0.1},
	/* 24 */ {0.25, 1, 0.25},
	/* 25 */ {1, 1, 0.25},
	/* 26 */ {1, 1, 0.25},
	/* 27 */ {0.15, 0.75, 0.15},
	/* 28 */ {0.15, 0.75, 0.15},
	/* 29 */ {0.15, 0.75, 0.15},
	/* 30 */ {0.5, 0.75, 0.5},
	/* 31 */ {0.5, 0.75, 0.5},
	/* 32 */ {0.5, 0.75, 0.5},
	/* 33 */ {0.5, 0.75, 0.5},
	/* 34 */ {0.3, 0.9, 0.3},
	/* 35 */ {0.6, 1, 0.25},
	/* 36 */ {0.6, 1, 0.25},
	/* 37 */ {0.25, 1, 1.25},
	/* 38 */ {0.5, 0.75, 0.25},
	/* 39 */ {0.5, 0.75, 0.25},
	/* 40 */ {},
	/* 41 */ {},
	/* 42 */ {},
	/* 43 */ {},
	/* 44 */ {},
	/* 45 */ {},
	/* 46 */ {},
	/* 47 */ {},
	/* 48 */ {},
	/* 49 */ {},
	/* 50 */ {},
	/* 51 */ {},
	/* 52 */ {},
	/* 53 */ {},
	/* 54 */ {},
	/* 55 */ {},
	/* 56 */ {},
	/* 57 */ {},
	/* 58 */ {},
	/* 59 */ {},
	/* 60 */ {},
	/* 61 */ {},
	/* 62 */ {},
	/* 63 */ {},
	/* 64 */ {},
	/* 65 */ {},
	/* 66 */ {},
	/* 67 */ {},
	/* 68 */ {},
	/* 69 */ {},
	/* 70 */ {},
	/* 71 */ {},
	/* 72 */ {},
	/* 73 */ {},
	/* 74 */ {},
	/* 75 */ {},
	/* 76 */ {},
	/* 77 */ {},
	/* 78 */ {},
	/* 79 */ {},
	/* 80 */ {},
	/* 81 */ {},
	/* 82 */ {},
	/* 83 */ {},
	/* 84 */ {},
	/* 85 */ {},
	/* 86 */ {},
	/* 87 */ {},
	/* 88 */ {},
	/* 89 */ {},
	/* 90 */ {},
	/* 91 */ {},
	/* 92 */ {},
	/* 93 */ {},
	/* 94 */ {},
	/* 95 */ {},
	/* 96 */ {},
	/* 97 */ {},
	/* 98 */ {},
	/* 99 */ {},
	/* 100 */ {},
	/* 101 */ {},
	/* 102 */ {},
	/* 103 */ {},
	/* 104 */ {},
	/* 105 */ {},
	/* 106 */ {},
	/* 107 */ {},
	/* 108 */ {},
	/* 109 */ {},
	/* 110 */ {},
	/* 111 */ {},
	/* 112 */ {},
	/* 113 */ {},
	/* 114 */ {},
	/* 115 */ {},
	/* 116 */ {},
	/* 117 */ {},
	/* 118 */ {},
	/* 119 */ {},
	/* 120 */ {},
	/* 121 */ {},
	/* 122 */ {},
	/* 123 */ {},
	/* 124 */ {},
	/* 125 */ {},
	/* 126 */ {},
	/* 127 */ {},
	/* 128 */ {0.3, 1, 0.3},
	/* 129 */ {0.3, 1, 0.3},
	/* 130 */ {1, 1, 0.25},
	/* 131 */ {0.3, 0.9, 0.3},
	/* 132 */ {0.15, 0.75, 0.15},
	/* 133 */ {0.5, 0.75, 0.5},
	/* 134 */ {0.75, 1, 0.25},
	/* 135 */ {},
	/* 136 */ {},
	/* 137 */ {},
	/* 138 */ {},
	/* 139 */ {},
	/* 140 */ {0.3, 1, 0.3},
	/* 141 */ {},
	/* 142 */ {},
	/* 143 */ {},
	/* 144 */ {},
	/* 145 */ {},
	/* 146 */ {},
	/* 147 */ {},
	/* 148 */ {},
	/* 149 */ {0.1, 1.25, 0.1},
	/* 150 */ {},
	/* 151 */ {0.1, 1.25, 0.1},
	/* 152 */ {},
	/* 153 */ {},
	/* 154 */ {},
	/* 155 */ {0.15, 0.75, 0.15},
	/* 156 */ {0.15, 0.75, 0.15},
	/* 157 */ {0.15, 0.75, 0.15},
	/* 158 */ {0.5, 0.75, 0.5},
	/* 159 */ {},
	/* 160 */ {0.5, 0.75, 0.5},
	/* 161 */ {0.5, 0.75, 0.5},
	/* 162 */ {0.3, 0.9, 0.3},
	/* 163 */ {0.6, 1, 0.25},
	/* 164 */ {0.6, 1, 0.25},
	/* 165 */ {0.25, 1, 1.25},
	/* 166 */ {0.25, 1, 1.25},
	/* 167 */ {0.25, 1, 1.25},
};

}
}
