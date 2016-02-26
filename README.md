# PositionalHeatmap
C and R application to create a heatmap of average quality scores on an Illumina machine



Hello - sorry, this project is still rough around the edges but it will slowly improve.

To compile:

```bash
gcc parse.c
```

To run:

With fastq files. 

```bash
Rscript <(./a.out <(cat <(zcat *.fastq.gz) <(cat *.fastq))) Title_of_Graph 1101
```
With sam files

```bash
Rscript <(./a.out <(cat *.sam | grep -v ^@ | awk '{print "@"$1"\n"$10"\n+\n"$11}') Title_of_Graph 1101
```

1101 can be replaced with whatever tile you are interested in.

Important: Be sure you have library fields and MBA installed in R
