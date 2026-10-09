import java.util.*;

class TimeMap {
    // key -> list of (timestamp, value); timestamps are strictly increasing
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
        int left = 0, right = list.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid).timestamp <= timestamp) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans == -1 ? "" : list.get(ans).value;
    }
}
