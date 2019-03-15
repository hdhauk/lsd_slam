FROM osrf/ros:melodic-desktop-full

RUN git clone https://github.com/RainerKuemmerle/g2o.git && \
cd g2o && \
mkdir _build && \
cmake -H. -B_build -DG2O_BUILD_EXAMPLES=OFF -DG2O_BUILD_APPS=OFF && \
cmake --build _build -- -j$(nproc)

RUN cd g2o && cmake --build _build --target install