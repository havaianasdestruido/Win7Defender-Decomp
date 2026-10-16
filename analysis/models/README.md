# Analysis behavior models

Code here is authored and executed by the analysis team to test behavioral
hypotheses against controlled original execution. It is **analysis-exposed**
and is not clean-room implementation source.

Models may depend on reviewed analysis findings, but must never be transferred
to Team B or copied under `implementation/`. Build products are ignored. Each
model documents its validation scope and exclusions.
