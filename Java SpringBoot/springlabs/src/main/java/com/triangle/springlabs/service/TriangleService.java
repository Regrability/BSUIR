package com.triangle.springlabs.service;


import com.triangle.springlabs.model.Triangle;
import com.triangle.springlabs.model.TriangleDB;
import com.triangle.springlabs.model.TrianglePostOut;
import com.triangle.springlabs.model.TriangleRequest;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Async;

import java.util.DoubleSummaryStatistics;
import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.function.ToDoubleFunction;
import java.util.stream.Collectors;


public class TriangleService {
    @Autowired
    private TriangleDBRepository triangleDBRepository;
    private final static Logger LOGGER = LoggerFactory.getLogger(TriangleService.class);
    public Triangle outTriangle(Triangle triangleInfo)
    {
        return triangleInfo;
    }
    public Triangle doTriangle(String aSide, String bSide, String cSide) {
        double sideA, sideB, sideC;
        Triangle triangleInfo;
        try
        {
            sideA = Double.parseDouble(aSide);
            sideB = Double.parseDouble(bSide);
            sideC = Double.parseDouble(cSide);
            triangleInfo = new Triangle(sideA,sideB,sideC);
        }
        catch (NumberFormatException e)
        {
            LOGGER.error("Invalid Enter");
            throw new IllegalStateException("Invalid Enter");
        }
        // Проверка на 0 или отрицательное
        if ( 0 >= sideC || 0 >= sideB || 0 >= sideA) {
            LOGGER.error("one of the sides is less than or equal to 0");
            throw new IllegalStateException("one of the sides is less than or equal to 0");
        }
        // Проверка на реальность треугольника
        if (sideA + sideB <= sideC || sideA + sideC <= sideB || sideB + sideC <= sideA) {
            LOGGER.error("There is no such triangle");
            throw new IllegalStateException("There is no such triangle");
        }
        LOGGER.info("Triangle is created");
        saveInDB(triangleInfo);
        return triangleInfo;

    }
   @Async
    public CompletableFuture<Triangle> doTriangleAsync(String aSide, String bSide, String cSide) {
        LOGGER.info("Service start work");
        Triangle triangle = doTriangle(aSide, bSide, cSide);
        LOGGER.info("Service end end");
        return CompletableFuture.completedFuture(triangle);
    }

    public void saveInDB(Triangle triangle)
    {
        Long id = triangleDBRepository.count();
        if (id == 0) {
            id = 1L;
        } else {
            id++;
        }
        // Проверяем наличие треугольника в базе данных
        if (!triangleDBRepository.checkExistsByPerimeterAndArea(triangle.getPerimeter(), triangle.getArea())) {
            TriangleDB triangleDB = new TriangleDB(triangle, id);
            triangleDBRepository.save(triangleDB);
        }
    }

    public void deleteDB()
    {
        triangleDBRepository.deleteAll();
    }

    public Iterable<TriangleDB> showDB()
    {
        return triangleDBRepository.findAll();
    }


    public TrianglePostOut doBulkTriangle(List<TriangleRequest> triangleRequests) {
        TrianglePostOut out = new TrianglePostOut();

        List<TriangleRequest> trianglesCheck = triangleRequests.stream()
                .filter(req -> isValidTriangle(req.getDoubleSideA(), req.getDoubleSideB(), req.getDoubleSideC()))
                .toList();

        List<Triangle> trianglesInfo = trianglesCheck.stream()
                .map(req -> doTriangle(req.getSideA(), req.getSideB(), req.getSideC()))
                .collect(Collectors.toList());

        out.setTriangles(trianglesInfo);

        // Статистика по периметру
        DoubleSummaryStatistics perimeterStats = trianglesInfo.stream()
                .mapToDouble(Triangle::getPerimeter)
                .summaryStatistics();
        out.setMaxPerimeter(perimeterStats.getMax());
        out.setMinPerimeter(perimeterStats.getMin());
        out.setAveragePerimeter(perimeterStats.getAverage());

        // Статистика по площади
        DoubleSummaryStatistics areaStats = trianglesInfo.stream()
                .mapToDouble(Triangle::getArea)
                .summaryStatistics();
        out.setMaxArea(areaStats.getMax());
        out.setMinArea(areaStats.getMin());
        out.setAverageArea(areaStats.getAverage());

        // Статистика по размерам сторон треугольников
        out.setMaxSizeA(getMaxSize(triangleRequests, TriangleRequest::getDoubleSideA));
        out.setMaxSizeB(getMaxSize(triangleRequests, TriangleRequest::getDoubleSideB));
        out.setMaxSizeC(getMaxSize(triangleRequests, TriangleRequest::getDoubleSideC));

        out.setMinSizeA(getMinSize(triangleRequests, TriangleRequest::getDoubleSideA));
        out.setMinSizeB(getMinSize(triangleRequests, TriangleRequest::getDoubleSideB));
        out.setMinSizeC(getMinSize(triangleRequests, TriangleRequest::getDoubleSideC));

        out.setAverageSizeA(getAverageSize(triangleRequests, TriangleRequest::getDoubleSideA));
        out.setAverageSizeB(getAverageSize(triangleRequests, TriangleRequest::getDoubleSideB));
        out.setAverageSizeC(getAverageSize(triangleRequests, TriangleRequest::getDoubleSideC));

        out.triangles.forEach(this::saveInDB);
        return out;
    }

    private double getMaxSize(List<TriangleRequest> triangleRequests, ToDoubleFunction<TriangleRequest> getSize) {
        return triangleRequests.stream()
                .mapToDouble(getSize)
                .max()
                .orElse(0.0);
    }

    private double getMinSize(List<TriangleRequest> triangleRequests, ToDoubleFunction<TriangleRequest> getSize) {
        return triangleRequests.stream()
                .mapToDouble(getSize)
                .min()
                .orElse(0.0);
    }

    private double getAverageSize(List<TriangleRequest> triangleRequests, ToDoubleFunction<TriangleRequest> getSize) {
        return triangleRequests.stream()
                .mapToDouble(getSize)
                .average()
                .orElse(0.0);
    }

    private boolean isValidTriangle(double sideA, double sideB, double sideC) {
        return sideA + sideB > sideC && sideB + sideC > sideA && sideA + sideC > sideB;
    }
}
