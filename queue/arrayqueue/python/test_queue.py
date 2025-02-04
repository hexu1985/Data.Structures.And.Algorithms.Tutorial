#!/usr/bin/env python3
"""
Testing the Queue module
Roman Yasinovskyy, 2017
Karina E. Hoff, 2018
"""


# Specifies the absolute path to the pythonds3 module
import os
import sys

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

import pytest
from arrayqueue import ArrayQueue as Queue


class TestQueueMethods:
    @pytest.fixture(autouse=True)
    def setup_class(self):
        """Setting up"""
        self.queue = Queue()

    def test_is_empty(self):
        """Testing is_empty() method"""
        assert self.queue.isEmpty()
        self.queue.add(42)
        assert not self.queue.isEmpty()

    def test_size(self):
        """Testing size() method"""
        assert len(self.queue) == 0
        self.queue.add(42)
        assert len(self.queue) == 1

    def test_enqueue(self):
        """Testing enqueue() method"""
        self.queue.add(42)
        assert len(self.queue) == 1

    def test_dequeue(self):
        """Testing dequeue() method"""
        self.queue.add(42)
        assert self.queue.pop() == 42
        assert self.queue.isEmpty()


if __name__ == "__main__":
    pytest.main(["test_queue.py"])
