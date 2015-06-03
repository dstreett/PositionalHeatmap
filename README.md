# PositionalHeatmap
C and R application to create a heatmap of average quality scores on an Illumina machine



Hello - sorry, this project is still rough around the edges but I will slowly improve.



To run:

With fastq files. 

./a.out <(cat <(zcat *.fastq.gz) <(cat *.fastq)) > test.sq

With sam files

./a.out <(cat *.sam | grep -v ^@ | awk '{print "@"$1"\n"$10"\n+\n"$11}') > test.sq



As of right now you can take this test.sq.

Rscript Heatmap_quality.R test.sq Title_of_Graph 1101
