package com.triangle.springlabs.service;

import com.triangle.springlabs.model.Triangle;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;


public class TriangleServiceTest {
    private TriangleService triangleService;

    @BeforeEach
    void setUp() {
        triangleService = new TriangleService();
    }

    @Test
    void testDoTriangle_InvalidSideFormat_ThrowsIllegalStateException() {
        // Arrange
        String aSide = "invalid";
        String bSide = "4";
        String cSide = "5";

        // Act & Assert
        Assertions.assertThrows(IllegalStateException.class, () -> triangleService.doTriangle(aSide, bSide, cSide));
    }


    @Test
    void testDoTriangle_ZeroSideFormat_ThrowsIllegalStateException() {
        // Arrange
        String aSide = "0";
        String bSide = "4";
        String cSide = "5";

        // Act & Assert
        Assertions.assertThrows(IllegalStateException.class, () -> triangleService.doTriangle(aSide, bSide, cSide));
    }

    @Test
    void testDoTriangle_SideFormatNotTriangle_ThrowsIllegalStateException() {
        // Arrange
        String aSide = "1";
        String bSide = "2";
        String cSide = "10";

        // Act & Assert
        Assertions.assertThrows(IllegalStateException.class, () -> triangleService.doTriangle(aSide, bSide, cSide));
    }

    @Test
    void testOutTriangle_ReturnsTriangle() {
        // Arrange
        Triangle triangle = Mockito.mock(Triangle.class);
        // Act
        Triangle result = triangleService.outTriangle(triangle);
        // Assert
        Assertions.assertEquals(triangle, result);
    }


}
