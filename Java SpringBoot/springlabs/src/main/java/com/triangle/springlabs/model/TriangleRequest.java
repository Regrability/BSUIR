package com.triangle.springlabs.model;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@AllArgsConstructor
@Getter
@Setter
public class TriangleRequest {
    private String sideA;
    private String sideB;
    private String sideC;

    public double getDoubleSideA() {
        return Double.parseDouble(sideA);
    }
    public double getDoubleSideB() { return Double.parseDouble(sideB); }
    public double getDoubleSideC() { return Double.parseDouble(sideC); }

}