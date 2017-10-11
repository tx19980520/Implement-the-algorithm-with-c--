#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class DisJointSet {
private:
	int size;
	int *parent;
	vector<int> for_conpress;
public:
	DisJointSet() {}
	DisJointSet(int n) :size(n) { parent = new int[n + 1]; }
	~DisJointSet() {}
	int find(int x);
	void Union(int root1, int root2);
	void insert(int root, int x);
	void insert(int x);
};