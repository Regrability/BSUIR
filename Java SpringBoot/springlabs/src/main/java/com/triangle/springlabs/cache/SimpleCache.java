package com.triangle.springlabs.cache;
import com.triangle.springlabs.model.Triangle;
import org.springframework.stereotype.Component;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
@Component
public class SimpleCache {
    private Map<String, Triangle> cache;
    public SimpleCache() {
        this.cache = new ConcurrentHashMap<>();
    }
    public void put(String key, Triangle value) {
        cache.put(key, value);
    }
    public Triangle get(String key) {
        return cache.get(key);
    }
    public void remove(String key) {
        cache.remove(key);
    }
    public void clear() {
        cache.clear();
    }
}
