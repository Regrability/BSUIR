package com.triangle.springlabs.model;
import java.util.List;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Data
public class TrianglePostOut {
    @JsonProperty("max_size_A")
    private double maxSizeA;
    @JsonProperty("max_size_B")
    private double maxSizeB;
    @JsonProperty("max_size_C")
    private double maxSizeC;

    @JsonProperty("min_size_A")
    private double minSizeA;
    @JsonProperty("min_size_B")
    private double minSizeB;
    @JsonProperty("min_size_C")
    private double minSizeC;

    @JsonProperty("average_size_A")
    private double averageSizeA;
    @JsonProperty("average_size_B")
    private double averageSizeB;
    @JsonProperty("average_size_C")
    private double averageSizeC;

    @JsonProperty("max_perimeter")
    private double maxPerimeter;
    @JsonProperty("max_area")
    private double maxArea;

    @JsonProperty("average_perimeter")
    private double averagePerimeter;
    @JsonProperty("average_area")
    private double averageArea;

    @JsonProperty("min_perimeter")
    private double minPerimeter;
    @JsonProperty("min_area")
    private double minArea;

    public List<Triangle> triangles;
}
