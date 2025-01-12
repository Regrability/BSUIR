package com.triangle.springlabs.schedule;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;

@Service
public class LogsPoster {
    private final static Logger LOGGER = LoggerFactory.getLogger(LogsPoster.class);

    public void postTrace(String message) {
        LOGGER.trace(message);
    }

    public void postDebug(String message) {
        LOGGER.debug(message);
    }

    public void postInfo(String message) {
        LOGGER.info(message);
    }

    public void postWarn(String message) {
        LOGGER.warn(message);
    }

    public void postError(String message) {
        LOGGER.error(message);
    }
}









































