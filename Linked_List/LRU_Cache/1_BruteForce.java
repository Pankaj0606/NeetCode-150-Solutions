import java.util.*;

class LRUCache {
    private final int capacity;
    private final List<int[]> items; // each int[]{key,value}, front = most recent
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.items = new ArrayList<>();
    }
    public int get(int key) {
        for (int i = 0; i < items.size(); i++) {
            int[] kv = items.get(i);
            if (kv[0] == key) {
                int val = kv[1];
                items.remove(i);
                items.add(0, new int[]{key, val});
                return val;
            }
        }
        return -1;
    }
    public void put(int key, int value) {
        for (int i = 0; i < items.size(); i++) {
            if (items.get(i)[0] == key) {
                items.remove(i);
                break;
            }
        }
        if (items.size() == capacity) {
            items.remove(items.size() - 1);
        }
        items.add(0, new int[]{key, value});
    }
}
