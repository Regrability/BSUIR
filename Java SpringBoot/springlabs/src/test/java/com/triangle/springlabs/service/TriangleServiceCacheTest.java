package com.triangle.springlabs.service;

import com.triangle.springlabs.cache.SimpleCache;
import com.triangle.springlabs.model.Triangle;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;


import static org.junit.jupiter.api.Assertions.assertTrue;

public class TriangleServiceCacheTest {

    private TriangleServiceCache triangleService;
    private SimpleCache MyCash;

    @BeforeEach
    void setUp() {
        triangleService = new TriangleServiceCache();
    }

    @Test
    void testDoTriangle_WithoutCachedTriangle() {
        // Arrange
        MyCash = new SimpleCache();
        String aSide = "3";
        String bSide = "4";
        String cSide = "5";
        String cacheKey = aSide + bSide + cSide;
        Triangle cachedTriangle = MyCash.get(cacheKey);
        if (cachedTriangle != null) {
            assertTrue(false);
        }
        else {
            Triangle triangleInfo = triangleService.doTriangle(aSide, bSide, cSide);
            MyCash.put(cacheKey, triangleInfo);
            assertTrue(true);
        }
    }
    @Test
    void testDoTriangle_WithCachedTriangle() {
        MyCash = new SimpleCache();

        Triangle triangleInfo = triangleService.doTriangle("3", "4", "5");
        String cacheKey = "345";
        MyCash.put(cacheKey, triangleInfo);

        String aSide = "3";
        String bSide = "4";
        String cSide = "5";
        cacheKey = aSide + bSide + cSide;
        Triangle cachedTriangle = MyCash.get(cacheKey);

        if (cachedTriangle == null) {
            assertTrue(false);
        }
        else{
        assertTrue(true);}
    }
}
