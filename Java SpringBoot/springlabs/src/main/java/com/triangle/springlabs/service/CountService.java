package com.triangle.springlabs.service;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

@Component
@Scope("singleton")
public class CountService
{
    private final static Logger LOGGER = LoggerFactory.getLogger(CountService.class);
    private int count;

    public  CountService()
    {
        count = 0;
    }
    public synchronized void increment() {
        count++;
        LOGGER.info("Number of requests to the service: " + count);
    }
    public synchronized int getCount() {
        return count;
    }

}
