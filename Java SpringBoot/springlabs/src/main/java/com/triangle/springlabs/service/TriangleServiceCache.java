package com.triangle.springlabs.service;

import com.triangle.springlabs.cache.SimpleCache;
import com.triangle.springlabs.model.Triangle;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.scheduling.annotation.Async;


public class TriangleServiceCache extends TriangleService{
    private final static Logger LOGGER = LoggerFactory.getLogger(TriangleServiceCache.class);
    SimpleCache MyCash;
    public TriangleServiceCache() {
        MyCash = new SimpleCache(); // инициализация объекта MyCash
    }
    @Override
    public Triangle doTriangle(String aSide, String bSide, String cSide) {


        String cacheKey = aSide + bSide + cSide;
        Triangle cachedTriangle = MyCash.get(cacheKey);
        if (cachedTriangle != null) {
            LOGGER.info("Triangle found in cache");
            return cachedTriangle;
        }
        Triangle triangleInfo = super.doTriangle(aSide, bSide, cSide);
        MyCash.put(cacheKey, triangleInfo);
        return triangleInfo;

    }
}
