import java.util.*;

class TimeMap {
    // key -> TreeMap of timestamp -> value (ordered)
    private Map<String, TreeMap<Integer, String>> store = new HashMap<>();

    public void set(String key, String value, int timestamp) {
        store.computeIfAbsent(key, k -> new TreeMap<>()).put(timestamp, value);
    }

    public String get(String key, int timestamp) {
        TreeMap<Integer, String> map = store.get(key);
        if (map == null) return "";
        Integer floorKey = map.floorKey(timestamp);
        return floorKey == null ? "" : map.get(floorKey);
    }
}
