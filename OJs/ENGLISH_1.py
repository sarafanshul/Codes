'''
 * Description:
 *  A trie is a tree data-structure that stores words by compressing common
 *  prefixes. To illustrate, following is a word list and its resulting trie.
 *
 *   WORDS: rat, rats, rattle, rate, rates, rating, can, cane,
 *          canny, cant, cans, cat, cats, cattle, cattles.
 *
 *   TRIE:
 *         ___________|____________
 *        |                        |
 *        r                        c
 *        a                ________a___________
 *        t~              |                    |
 *    ____|_____          n~                   t~
 *   |   |  |   |    _____|_____        _______|______
 *   s~  t  e~  i   |   |   |   |      |              t
 *       l  s~  n   e~  n   t~  s~     s~             l
 *       e~     g~      y~                            e~
 *                                                    s~
 *
 *   Each ~ in the figure indicates where a prefix is a word.
 *
 *   Generally, a trie has all the benefits of a hash table without
 *   any of the disadvantages.
 *
 *   --------------------------------------------------------------
 *          | HASH TABLE | TRIE     | explanations
 *   --------------------------------------------------------------
 *   Memory |    O(n)    |  < O(n)  | trie uses prefix compression.
 *          |            |          | Hence it does not store each
 *          |            |          | word explicitly
 *  ----------------------------------------------------------------
 *   Search |   O(1)     |  O(1)    | trie is technically faster.
 *          |            | pseudo-  | Given a word, computing a
 *          |            | constant | hash takes at least as long
 *          |            |          | as traversing a trie. Plus,
 *          |            |          | trie has no collision.
 *  ----------------------------------------------------------------
 *
 *  Tries are particularly superior to hash tables when it comes to solving
 *  problems such as word puzzles like boggle. In such puzzles the objective
 *  is to find how many words in a given list are valid. So if for example
 *  at a particular instance in boggle you have a list of one billion words
 *  all starting with zh-, whereas the dictionary has no words starting with
 *  zh-; then: if the dictionary is a hash table, you must compute the entire
 *  hashcode for each word and do one billion look-ups; if on the other hand
 *  the dictionary is a trie, you only do the equivalent of partially
 *  computing one hashcode! That's a saving of over one billion fold!
 *
 *  This implementations of trie uses an array to store the children
 *  nodes, where the numerical value of each char serves as index.
 **************************************************************************/
'''
import sys
sys.setrecursionlimit(100000)
# from collections import defaultdict
# import heapq

'''
heapq and defaultdict does not work on codechef judge :(
use a simple dict and implement minheap
'''

class Struct():
	'''Well , we dont have those :('''
	def __init__(self ,v ,k):
		self.v = v
		self.k = k

	def getValue(self):
		return self.v

	def getKey(self):
		return self.k

	def setKey(self ,k1):
		old = self.k
		self.k = k1
		return old


class Heap(object):
	'''Convenctional heap with a little twist'''
	def __init__(self):
		self.heap = []
		# self.indexOfValue = defaultdict(lambda : None)
		self.indexOfValue = dict()

	def size(self):
		return len(self.heap)

	def isEmpty(self):
		return not(bool(len(self.heap)))

	def add(self ,V ,K):
		self.heap.append(Struct(V ,K))
		self.indexOfValue[V] = self.size() -1
		self.decreaseKey(V ,K)

	def compare(self ,a ,b): #use minus
		return a - b
	
	def parent(self ,idx):
		return 0 if idx == 0 else (idx-1) >> 1

	def decreaseKey(self ,V ,K):
		i = self.indexOfValue[V]
		if self.compare(K , self.heap[i].getKey()) > 0 : print("error-small need")
		self.heap[i].setKey(K)
		
		while i >0 and self.compare(self.heap[self.parent(i)].getKey() ,self.heap[i].getKey())>0:
			temp = self.heap[i]
			self.heap[i] = self.heap[self.parent(i)]
			self.indexOfValue[self.heap[self.parent(i)].getValue()] = i
			self.heap[self.parent(i)] = temp
			self.indexOfValue[temp.getValue()] = self.parent(i)
			i = self.parent(i)

	def peek(self):
		return self.heap[0].getValue()

	def extractMin(self):
		_min = self.peek()
		self.heap[0] = self.heap[self.size()-1]
		self.indexOfValue[self.heap[0].getValue()] = 0
		self.heap.pop(self.size()-1)
		self.indexOfValue[_min] = None
		self.heapify(0)
		return _min

	def left(self ,idx):
		return (idx<<1)+1

	def right(self ,idx):
		return (idx<<1)+2

	def heapify(self ,i):
		l = self.left(i)
		r = self.right(i)
		smallest = i

		if l < self.size() and self.compare(self.heap[l].getKey() ,self.heap[i].getKey()) < 0:
			smallest = l
		if r < self.size() and self.compare(self.heap[r].getKey() ,self.heap[smallest].getKey()) < 0:
			smallest = r
		if smallest == i:
			return

		temp = self.heap[i]
		self.heap[i] = self.heap[smallest]
		self.indexOfValue[self.heap[smallest].getValue()] = i
		self.heap[smallest] = temp
		self.indexOfValue[temp.getValue() ] = smallest
		self.heapify(smallest)


class TrieNode(object):
	'''A full passage about these on Top'''

	def __init__(self ,*args):
		self.children = dict()
		self.count = 0
		self.key = None
		self.parent = None
		self.depth = 0
		# self.children = defaultdict(lambda : None)

	def add(self ,s:str):

		self.count += 1
		for i in range(len(s)):
			c = s[i]
			d = s[len(s) -1 -i]
			key = (ord(c) - ord('a')) * 26 + (ord(d) - ord('a'))

			# if not self.children[key]:
			# 	self.children[key] = TrieNode()
			if not key in self.children.keys():
				self.children[key] = TrieNode()

			self.children[key].parent = self
			self.children[key].depth = self.depth + 1
			self = self.children[key]
			self.count += 1
			self.key = key


def dfs(node ,heap) -> None:

	if node.count >= 2:
		heap.add(node , -node.depth) # add nodes to the heap

	for child in node.children.values():
		dfs(child ,heap)

	return


def main() -> None:

	for _ in range(int(input())):

		ans = 0
		heap = Heap()
		root = TrieNode()

		for i in range(int(input())):
			root.add(input())

		dfs(root ,heap) # for traversal lol

		while not heap.isEmpty():

			deepest = heap.extractMin() # <class '__main__.TrieNode'>
			if deepest.count < 2: 
				continue

			_ft = None
			_sd = None
			depth = deepest.depth

			for x in deepest.children.keys():
				if _ft == None : _ft = x
				elif _sd == None : _sd = x
				else: break

			deepest.children[_ft] = None
			deepest.children[_sd] = None
			deepest.count -= 2

			if deepest.count >= 2:
				heap.add(deepest ,-deepest.depth)
			
			while deepest.parent != None:
				deepest.parent.count -= 2
				deepest.parent.children[deepest.key] = None
				deepest = deepest.parent

			ans += depth*depth
		# finally
		print(ans)

if __name__ == '__main__':
	main()