package com.triangle.springlabs.model;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
@Entity
public class TriangleDB {
    @Id
    private Long id;

    private double perimeter;
    private double area;

    public TriangleDB() {
        this.perimeter = 0;
        this.area = 0;
    }
    public TriangleDB(Triangle triangle, Long id) {
        this.id = id;
        this.perimeter = triangle.getPerimeter();
        this.area = triangle.getArea();
    }

}
