#! /usr/bin/env bash

set -eu
set -o xtrace
set -o pipefail

for strat in "majority" "stochastic";
do
	ococo \
		-m batch \
		-i data/alignment_AA_unm.sam \
		-f data/fasta_NN.fa \
		-F output/fasta_NN.fa \
		-t $strat \
		-V - \

	diff output/fasta_NN.fa data/fasta_NN.fa

	echo
	echo "==============================="
	echo
done
