import java.util.*;

class TimeMap {
    // key -> list of (timestamp, value) preserving insertion order
    private Map<String, List<Pair>> store = new HashMap<>();

    private static class Pair {
        int timestamp;
        String value;
        Pair(int t, String v) { timestamp = t; value = v; }
    }

    public void set(String key, String value, int timestamp) {
        store.computeIfAbsent(key, k -> new ArrayList<>()).add(new Pair(timestamp, value));
    }

    public String get(String key, int timestamp) {
        List<Pair> list = store.get(key);
        if (list == null) return "";
        // Linear scan from the end (worst‑case O(N))
        for (int i = list.size() - 1; i >= 0; --i) {
            if (list.get(i).timestamp <= timestamp) return list.get(i).value;
        }
        return "";
    }
}
