# TnT - A Statistical Part-of-Speech Tagger
> We argue that a tagger based on Markov models performs at least as well as other approaches, includign the Maximum
Entropy framework. 
> We describe the basic model of TnT, the techniques used for smoothing and for handling 
unknown words.

https://dl.acm.org/citation.cfm?id=974178

##  Architecture
### The Underlying Model
1. As a first step, we use the maximum likehood probabilities P^ which are derived from the relative frequencies:

2. As second step, contextual frequencies are smoothed and lexical frequencies are completed by handling
words that are not in the lexicon.

## Smoothing 
> the sparse-date problem.

The smoothing paradigm that delivers the best results in TnT is linear interpolation of
unigrams, bigrams, and trigrams. There, we estimate a trigram probability as follows:
P(t3| t1, t2) = λ1 * P^(t3) + λ2 * P^(t3|t2) + λ3 * P^(t3| t1, t2)
λ1 + λ2 + λ3 = 1.0

The value of λ1, λ2, λ3 are estimated by deleted interpolation.
Due to sparse-date problems, one can't estimate a different set of λs for each trigram.
Therefore, it is common practice to group trigrams by frequency and estimate tied sets of λs.


Training the λs can be done so as to maximize the likelihood of a held-out data, 
separate from the main training corpus: 
    1. For each set of λs, one can compute the likelihood of the given data.
    2. Find this set of λs that gives the highest value.
    3. This is conceptually a search procedure, that can be done more efficiently using 
        a version of the EM algorithm.

## Handling of Unknown Words
The probability distribution for a particular suffix(后缀) is generated from all words 
in the training set that share the same suffix of some predefined maximum length.
The term suffix as used here means "final sequence of characters of a word" which is not necessarily 
meaningful suffix.

## Capitalization
Tags are usually not information about capitalization, but probability distributions 
of tags around capitalized words are different from those not capitalized. 


## Beam Search
The processing time of the Viterbi algorithm can be reduced by introducing a beam
search (柱搜索).

Each state that receives a δ value smaller than the larges δ divided by some 
threshold value θ is excluded from further processing. 

While the Viterbi algorithm is guaranteed to find the sequence of states with the highest
probability, this is no longer true when beam search is added.

Nevertheless, for practical purpose and the right choice of θ, there is virtually (实际上) 
no difference between the algorithm with and without a beam.

here, θ = 1000.


## Conclusion
- Handling of start and end-of-sequence
- The weights for context probabilities
- details on handling unknown words
- how to determine the weights for unknown words.

 













 
 
