class Graph:
	elements = {}
	def __init__(self, node, edges):
		self.elements[node] = edges

	def addEdge(self, node ,edge):
		if node in self.elements.keys():
			self.elements[node] += [edge]
		else:
			self.elements[node] = [edge]
	def getAdjencyList(self):
		return self.elements
	def getAdjencyMatrix(self):
		keys = list(self.elements.keys())
		ret =  [[0] * len(keys) for i in range(len(keys))]
		for k in range(len(keys)):
			for j in range(len(self.elements[keys[k]])):
				ret[keys[k]-1][self.elements[keys[k]][j][0]-1] = self.elements[keys[k]][j][1]
		return ret

if __name__ == "__main__":
	g =Graph(1,[[2,1],[3,1]])
	g.addEdge(2,[3,3])
	g.addEdge(3,[4,4])
	g.addEdge(4,[1,5])
	print(g.getAdjencyList())
	print()
	print(g.getAdjencyMatrix())