class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
        self.hashmap = {}

    def add_to_front(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.hashmap[val] = new_node
        self.size += 1

    def add_to_back(self, val):
        new_node = Node(val)
        if self.tail is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.hashmap[val] = new_node
        self.size += 1

    def remove(self, val):
        if val not in self.hashmap:
            return
        node_to_delete = self.hashmap[val]
        if node_to_delete == self.head:
            self.head = node_to_delete.next
        if node_to_delete == self.tail:
            self.tail = node_to_delete.prev
        if node_to_delete.prev:
            node_to_delete.prev.next = node_to_delete.next
        if node_to_delete.next:
            node_to_delete.next.prev = node_to_delete.prev
        del self.hashmap[val]
        self.size -= 1

    def swap(self, val1, val2):
        if val1 not in self.hashmap or val2 not in self.hashmap:
            return
        node1 = self.hashmap[val1]
        node2 = self.hashmap[val2]
        node1.val, node2.val = node2.val, node1.val
        self.hashmap[val1], self.hashmap[val2] = node2, node1

    def contains(self, val):
        return val in self.hashmap

    def __str__(self):
        values = []
        curr = self.head
        while curr:
            values.append(str(curr.val))
            curr = curr.next
        return ' -> '.join(values)


'''
my_list = DoublyLinkedList()
my_list.add_to_front(1)
my_list.add_to_back(2)
my_list.add_to_front(3)
print(my_list)  # Output: 3 -> 1 -> 2
my_list.swap(1, 2)
print(my_list)  # Output: 3 -> 2 -> 1
my_list.remove(2)
print(my_list)  # Output: 3 -> 1
print(my_list.contains(1))  # Output: True
print(my_list.contains(2))  # Output: False

'''
