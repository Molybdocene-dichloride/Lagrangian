#pragma once

class BlockPos;
class Vec3;

class ChunkPos {
	public:
    int chunkXPos, chunkZPos;

	ChunkPos(Vec3 const&);
	ChunkPos(BlockPos const&);
	BlockPos getMiddleBlockPosition(int) const;
};