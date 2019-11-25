import logging
handler=logging.StreamHandler()
formatter =logging.Formatter("%(asctime)s - %(name)s - %(levelname)s - %(message)s")
handler.setFormatter(formatter)
logger=logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.addHandler(handler)

logger.debug("이 메시지는 개발자만 이해함")
logger.info("생각대로 동작 중")
logger.warn("곧 문제가 생길 가능성 높음")
logger.error("문제 발생, 기능 동작 안함")
logger.critical("시스템이 다운")
