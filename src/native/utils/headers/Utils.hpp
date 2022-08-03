namespace RotationTransforms {
	vector<vector<char>> rotationMap [
		[3, 2, 0, 1, 4, 5],
		[2, 3, 1, 0, 5, 4],
		[0, 1, 3, 2, 5, 4],
		[0, 1, 2, 3, 4, 5],
		[0, 1, 4, 5, 3, 2],
		[0, 1, 5, 4, 2, 3],
	]
	char worldRotationToBlockRotation(rotation, rotationOfBlock) {
		Logger.Log(rotationOfBlock, "@seao");
		if(rotationOfBlock == 3) {
			return rotation;
		}
		let e;
		for(let i = 0; i < RotationTransforms.rotationMap[3].length; i++) {
			if(RotationTransforms.rotationMap[3][i] == rotation) e = i;
		}
		return RotationTransforms.rotationMap[rotationOfBlock][e];
	}
	char blockRotationToWorldRotation(rotation, rotationOfBlock) {
		Logger.Log(rotationOfBlock, "@sas");
		if(rotationOfBlock == 3) {
			return rotation;
		}
		let e;
		for(let i = 0; i < RotationTransforms.rotationMap[rotationOfBlock].length; i++) {
			if(RotationTransforms.rotationMap[rotationOfBlock][i] == rotation) e = i;
		}
		Logger.Log(e, "@e");
		Logger.Log(RotationTransforms.rotationMap[3][e], "@sashok");
		return RotationTransforms.rotationMap[3][e];
	}
	
	directions: [
		{x: 0, y: -1, z: 0}, // down
		{x: 0, y: 1, z: 0}, // up
		{x: 0, y: 0, z: -1}, // east
		{x: 0, y: 0, z: 1}, // west
		{x: -1, y: 0, z: 0}, // south
		{x: 1, y: 0, z: 0} // north
	],
	getSide: function(relative) {
	  for(let i = 0; i < this.directions.length; i++) {
	    if(this.directions[i].x == relative.x & this.directions[i].y == relative.y & this.directions[i].z == relative.z) {
	      return i;
	    }
	  }
	  return null;
	},
	getRelativeSide: function(coords1/*main side*/, coords2) {
	  let relative = {x: coords2.x - coords1.x, y: coords2.y - coords1.y, z: coords2.z - coords1.z};
	  return this.getSide(relative);
	},
	getRelativeCoords: function(x, y, z, side) {
		let dir = this.directions[side];
		return {x: x + dir.x, y: y + dir.y, z: z + dir.z};
	},
}
