#pragma once

//#include <mcpe/math/BlockPos.hpp>

class Rotation;
class Mirror;
class SubChunkPos;
class BlockPos;
class ChunkBlockPos;
class Vec3;
class ChunkPos;

class BlockPos {
	public:
	int x, y, z;
	
	BlockPos(Vec3 const&);
	BlockPos(ChunkPos const&, int);
	BlockPos(SubChunkPos const&, int);
	BlockPos(ChunkPos const&, ChunkBlockPos const&, short);
	BlockPos(float, float, float);
	BlockPos(double, double, double);
	void relative(unsigned char, int) const;
	void randomFloat() const;
	void randomSeed() const;
	void neighbor(unsigned char) const;
	newstd::string toString() const;
	void center() const;
	//void transform(Rotation, Mirror, Vec3 const&) const;
	public:
	static BlockPos * ZERO;
	static BlockPos * MIN;
	static BlockPos * MAX;
	static BlockPos * ONE;
};
