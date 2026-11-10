# Green Tech Efficiency and Benchmarking Analysis

## Measurement Methodology

The purpose of this experiment was to examine how execution time changes across different C programs and implementations. I used the provided programs without changing their original algorithms or input data. I compiled the programs using the required GCC flags and performed the measurements in the same development environment.

For the baseline experiment, I executed a loop containing 100 million iterations three consecutive times. For the algorithm comparison, I executed the provided program three times and recorded the timing of both implementations during each run. I calculated the averages from the recorded values rather than relying on a single observation.

The programs used `clock()` and `CLOCKS_PER_SEC` to express measured processor time in seconds. For the instrumentation experiment, I measured dataset construction, processing, and checksum reduction separately. I placed the total measurement around all three phases, allowing me to compare the overall execution time with individual phase timings.

## Observed Performance Differences

The baseline loop produced execution times of 0.227665, 0.228729, and 0.229249 seconds. Its average was 0.228548 seconds. The difference between the fastest and slowest recorded runs was 0.001584 seconds. These observations show that repeated executions of the same program did not produce perfectly identical timings.

The naive algorithm recorded 2.773332, 2.774172, and 2.762362 seconds, giving an average of 2.769955 seconds. The single-pass implementation recorded 0.000106, 0.000105, and 0.000106 seconds, giving an average of 0.000106 seconds.

Based on these measured averages, the naive implementation took approximately 26,214.09 times as long as the single-pass implementation. The programs also reported different counting results because the naive algorithm repeatedly counts elements inside nested loops, while the single-pass version counts each even element once. Therefore, the timing comparison demonstrates the cost of repeated work, but the two return values do not represent identical computations.

The instrumentation experiment recorded a total of 0.000799 seconds. Building the dataset took 0.000318 seconds, processing took 0.000337 seconds, and reducing the checksum took 0.000137 seconds. Of these individually measured phases, PROCESS had the largest recorded duration.

## Relation Between Runtime and Energy Consumption

Execution time matters because a processor performing work for longer may consume more energy. In my measurements, the naive implementation required substantially more processor time than the single-pass implementation. This makes avoiding unnecessary repeated operations a reasonable efficiency goal.

However, the results do not establish how many watts or joules either program consumed. They provide timing evidence, not direct electrical measurements. Consequently, I can discuss potential energy-efficiency implications, but I cannot calculate actual energy savings from this experiment.

## Limitations of the Experiment

One limitation is that only three runs were recorded for the baseline and algorithm comparison, so the sample is small. Another limitation is that `clock()` measures processor time rather than direct energy consumption. Operating conditions, compilation settings, and measurement precision may also influence recorded times.

The instrumentation results represent one measured execution, and extremely short phases may be difficult to compare precisely. Additionally, the algorithm comparison uses implementations with different counting behavior, which limits claims about equivalent outputs. The experiment therefore supports a comparison of observed execution costs rather than a complete assessment of software sustainability.

## Practical Engineering Takeaway

My main takeaway is that measuring software provides stronger evidence than assuming an implementation is efficient. The baseline experiment demonstrated timing variability, the algorithm comparison revealed the cost of repeated processing, and the instrumentation experiment showed how execution time can be separated by program phase.

In future programming work, I would first confirm that implementations produce the required results, then benchmark them under consistent conditions. I would also repeat measurements and examine the most expensive phases before making changes. This approach connects programming decisions to observed performance without treating faster execution as proof of a specific reduction in energy use.
