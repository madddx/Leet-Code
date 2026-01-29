class Solution(object):
	def minimumCost(self, source, target, original, changed, cost):
		self.constructGraph(original, changed, cost)
		self.floydWarshall()

		cost = 0

		for i in range(len(source)):
			if(source[i] == target[i]):
				continue
			try:
				sourceIndex = self.index[source[i]]
				targetIndex = self.index[target[i]]
				transformCost = self.matrix[sourceIndex][targetIndex]
				if transformCost == -1:
					return -1
				cost += transformCost
			except:
				return -1
		return cost
		

	def constructGraph(self, original, changed, cost):
		nodes = sorted(set(original) | set(changed))
		index = {node: i for i, node in enumerate(nodes)}
		self.index = index

		n = len(nodes)
		matrix = [[-1] * n for _ in range(n)]

		for i in range(n):
			matrix[i][i] = 0
		for u, v, w in zip(original, changed, cost):
			matrix[index[u]][index[v]] = min(matrix[index[u]][index[v]], w) if matrix[index[u]][index[v]] != -1 else w

		self.matrix = matrix
	
	def floydWarshall(self):
		mat = self.matrix
		V = len(mat)

		for k in range(V):
			for i in range(V):
				for j in range(V):
					if ((mat[i][j] == -1 or mat[i][j] > (mat[i][k] + mat[k][j])) and (mat[k][j] != -1 and mat[i][k] != -1)):
						mat[i][j] = mat[i][k] + mat[k][j]
