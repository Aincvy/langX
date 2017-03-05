#pragma once
#include "Object.h"

namespace langX {
	// 运算这个节点
	void __execNode(Node *);

	//递归释放节点及子节点值的内存, 如果节点是 一个获得数组元素的节点， 同样释放 indexNode 节点的值内存
	void recursiveFreeNodeValue(Node *n);
}