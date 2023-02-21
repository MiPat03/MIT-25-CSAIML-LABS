class Queue:
	stack1, stack2 = [], []
	def __init__(self):
		stack1 = []
		stack2 = []
	def enqueue(self, ele):
		self.stack1 += [ele]
	def dequeue(self):
		if len(self.stack2) != 0:
			return self.stack2.pop()
		elif len(self.stack1) != 0:
			while len(self.stack1) != 0:
				self.stack2 += [self.stack1.pop()]
			return self.stack2.pop()
		return None

if __name__ == "__main__":
	q = Queue()
	q.enqueue(5)
	q.enqueue(6)
	print(q.dequeue())
	q.enqueue(7)
	print(q.dequeue())