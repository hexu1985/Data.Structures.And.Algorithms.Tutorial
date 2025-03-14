#!/usr/bin/env python3
"""
Testing the Stack module
Roman Yasinovskyy, 2017
Karina E. Hoff, 2018
"""


# Specifies the absolute path to the pythonds3 module
import os
import sys

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

import pytest
from linkedstack import LinkedStack as Stack


class TestStackMethods:
    @pytest.fixture(autouse=True)
    def setup_class(self):
        """Setting up"""
        self.stack = Stack()

    def test_is_empty(self):
        """Testing is_empty() method"""
        assert self.stack.isEmpty()
        self.stack.push(42)
        assert not self.stack.isEmpty()

    def test_size(self):
        """Testing size() method"""
        assert len(self.stack) == 0
        self.stack.push(42)
        assert len(self.stack) == 1

    def test_push(self):
        """Testing push() method"""
        self.stack.push(42)
        assert len(self.stack) == 1

    def test_pop(self):
        """Testing pop() method"""
        self.stack.push(42)
        assert self.stack.pop() == 42
        assert self.stack.isEmpty()

    def test_peek(self):
        """Testing peek() method"""
        self.stack.push(42)
        assert self.stack.peek() == 42
        assert len(self.stack) == 1


if __name__ == "__main__":
    pytest.main(["test_stack.py"])
