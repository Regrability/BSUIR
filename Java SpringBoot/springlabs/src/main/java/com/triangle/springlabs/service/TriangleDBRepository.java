package com.triangle.springlabs.service;

import com.triangle.springlabs.model.TriangleDB;
import org.springframework.data.repository.CrudRepository;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public interface TriangleDBRepository extends CrudRepository<TriangleDB, Long> {
    Logger logger = LoggerFactory.getLogger(TriangleDBRepository.class);

    boolean existsByPerimeterAndArea(double perimeter, double area);

    default boolean checkExistsByPerimeterAndArea(double perimeter, double area) {
        boolean exists = existsByPerimeterAndArea(perimeter, area);
        if (exists) {
            logger.info("Triangle with perimeter {} and area {} now is on Data Base", perimeter, area);
        } else {
            logger.info("Triangle with perimeter {} and area {} add on Data Base", perimeter, area);
        }
        return exists;
    }
}
