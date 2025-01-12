package com.triangle.springlabs.controller;

import com.triangle.springlabs.model.Triangle;
import com.triangle.springlabs.model.TriangleDB;
import com.triangle.springlabs.model.TriangleRequest;
import com.triangle.springlabs.service.CountService;
import lombok.AllArgsConstructor;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import com.triangle.springlabs.service.TriangleService;
import com.triangle.springlabs.model.TrianglePostOut;

import java.util.List;
import java.util.concurrent.CompletableFuture;

@RestController
@RequestMapping("/api/v1/triangle")
@AllArgsConstructor

public class TriangleController {
private TriangleService triangleService;
private CountService countService;
private final static Logger LOGGER = LoggerFactory.getLogger(TriangleController.class);

    @GetMapping
    public Triangle calculateTriangle   (@RequestParam("sideA") String sideA,
                                         @RequestParam("sideB") String sideB,
                                         @RequestParam("sideC") String sideC) {
        countService.increment();
        return triangleService.doTriangle(sideA, sideB, sideC);
    }

    @GetMapping("/async")
    public ResponseEntity<String> calculateTriangleAsync(@RequestParam("sideA") String sideA,
                                                         @RequestParam("sideB") String sideB,
                                                         @RequestParam("sideC") String sideC) {
        CompletableFuture<Triangle> triangleFuture = triangleService.doTriangleAsync(sideA, sideB, sideC);
        LOGGER.info("Controller sends status 202");
        return ResponseEntity.accepted().body("Request accepted for processing");
    }

    @GetMapping("/database")
    public Iterable<TriangleDB> getTriangleFromDB   () {
        countService.increment();
        return triangleService.showDB();
    }

    @PostMapping("/bulk")
    public TrianglePostOut calculateBulkTriangle(@RequestBody List<TriangleRequest> triangleRequests) {
        countService.increment();
        return triangleService.doBulkTriangle(triangleRequests);
    }

    @DeleteMapping("/database/clean")
    public void cleanDatabase() {
        countService.increment();
        triangleService.deleteDB();
    }

}