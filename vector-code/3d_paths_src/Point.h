/*
 * Grid.h
 *
 *  Created on: Jan 18, 2019
 *      Author: Dingkang Wang
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <vector>
#include <cmath>

class Point {

public:
	// starting x, y;
	int x, y, z;
	// intensity;
	int s;

	Point(int _x, int _y, int z, int _s) :
			x(_x), y(_y), s(_s) {
	}

	bool operator==(const Point &another) const {
		return (x == another.x && y == another.y && z == another.z);
	}

	double get_distance(const Point &another) const {
		double dx = another.x - x, dy = another.y - y, dz = another.z - z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}


};

namespace std {
template<>
struct hash<Point> {
	size_t operator()(const Point &p) const {
		size_t res = 17;
		res = res * 31 + hash<int>()(p.x);
		res = res * 31 + hash<int>()(p.y);
		res = res * 31 + hash<int>()(p.z);
		return res;
	}
};
}

#endif /* POINT_H_ */
