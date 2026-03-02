# Queue Data Structure

## Overview
- **FIFO (First In, First Out):** The element that is inserted first is the one that is removed first.
- **Front:** Points to the element to be removed.
- **Rear:** Points to the last element inserted.

## Operations
1. **Enqueue (Insert):** Adds an element to the rear of the queue.
2. **Dequeue (Delete):** Removes an element from the front of the queue.
3. **Peek:** Returns the element at the front without removing it.

---

## Linear Queue
A simple queue implemented using an array where insertion happens at one end and deletion at the other.

### Limitations:
- **Memory Wastage:** Once the `Rear` reaches the end of the array, we cannot insert more elements even if there is space at the front (due to previous deletions).

---

## Circular Queue
A circular queue overcomes the limitation of a linear queue by connecting the last position back to the first position, forming a circle.

### Key Logic:
- **Circular Increment:** `(index + 1) % Size`
- **Queue Full Condition:** `(Rear + 1) % Size == Front`
- **Queue Empty Condition:** `Front == -1`

### Advantages:
- **Efficient Space Utilization:** Reuses the empty spaces created by deletions at the front of the queue.
