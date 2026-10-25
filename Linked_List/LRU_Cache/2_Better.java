import java.util.*;

class LRUCache {
    private final int capacity;
    private final LinkedList<int[]> list; // front = most recent
    private final Map<Integer, Integer> map; // key -> value for O(1) existence
    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.list = new LinkedList<>();
        this.map = new HashMap<>();
    }
    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        // Linear search in list to move node to front (O(N))
        Iterator<int[]> it = list.iterator();
        while (it.hasNext()) {
            int[] kv = it.next();
            if (kv[0] == key) {
                it.remove();
                list.addFirst(kv);
                return kv[1];
            }
        }
        return -1; // should not happen
    }
    public void put(int key, int value) {
        if (map.containsKey(key)) {
            // Remove old entry from list (O(N))
            Iterator<int[]> it = list.iterator();
            while (it.hasNext()) {
                int[] kv = it.next();
                if (kv[0] == key) { it.remove(); break; }
            }
        } else if (list.size() == capacity) {
            int[] lru = list.removeLast();
            map.remove(lru[0]);
        }
        list.addFirst(new int[]{key, value});
        map.put(key, value);
    }
}
