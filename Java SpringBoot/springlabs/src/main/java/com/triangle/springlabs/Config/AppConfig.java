package com.triangle.springlabs.Config;

import com.triangle.springlabs.cache.SimpleCache;
import com.triangle.springlabs.service.CountService;
import com.triangle.springlabs.service.TriangleService;
import com.triangle.springlabs.service.TriangleServiceCache;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.scheduling.annotation.EnableAsync;
import org.springframework.scheduling.concurrent.ThreadPoolTaskExecutor;

import java.util.concurrent.Executor;

@Configuration
@EnableAsync
public class AppConfig {

    @Value("${isCashed}")
    private Boolean isCashed;

    @Bean
    public Executor asyncExecutor() {
        ThreadPoolTaskExecutor executor = new ThreadPoolTaskExecutor();
        executor.setCorePoolSize(5); // Установите желаемое количество потоков
        executor.setMaxPoolSize(10); // Установите максимальное количество потоков
        executor.setQueueCapacity(25); // Установите размер очереди задач
        executor.initialize();
        return executor;
    }



    @Bean
    public SimpleCache SimpleCache() {
        return new SimpleCache();
    }
    @Bean
    public CountService CountService() {
        return new CountService();
    }




    @Bean
    public TriangleService TriangleService() {
        if(isCashed)
        return new TriangleServiceCache();
        return new TriangleService();
    }
}
