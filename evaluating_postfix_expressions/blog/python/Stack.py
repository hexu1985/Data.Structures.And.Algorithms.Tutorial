
class Stack:
    def __init__(self):
        self.items = list()

    def __len__(self):
        return len(self.items)

    def __str__(self):
        return "[" + ", ".join(map(str, self.items)) + "]"

    def __iter__(self):
        return iter(self.items)

    def isEmpty(self):
        return len(self.items) == 0

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.isEmpty():
            raise KeyError("The stack is empty")
        return self.items.pop()

    def peek(self):
        if self.isEmpty():
            raise KeyError("The stack is empty")
        return self.items[-1]

    def clear(self):
        self.items = list()

