package com.triangle.springlabs.model;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Data
public class Triangle {
    private double perimeter;
    private double area;

public Triangle(double sideA,double sideB,double sideC)
{
    this.perimeter = sideA + sideB + sideC;
    double s = perimeter / 2;  // Полупериметр
    this.area = Math.sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));  // Формула Герона для расчета площади
}

    public Triangle(String aSide, String bSide, String cSide) {
        double sideA = Double.parseDouble(aSide);
        double sideB = Double.parseDouble(bSide);
        double sideC = Double.parseDouble(cSide);
        this.perimeter = sideA + sideB + sideC;
        double s = perimeter / 2;  // Полупериметр
        this.area = Math.sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));  // Формула Герона для расчета площади
    }
}
