# Character-Based Generative model 
> http://aclweb.org/anthology//Y/Y09/Y09-2047.pdf

> 1. traditional word-based n-gram model, a generative approach, can't handle OOV words in out-of-vocabulary(in the testing-set).
> 2. character-based discriminative approach, poor performance for those in-vocabulary(IV) words that have been observed before.


To incorporate the intra-word(词内) characters dependency, a character-based approach with a 
generative model is thus proposed.


## Word-Based Generative Model
those OOV words are forced to be segmented into more words with smaller size.


## Character-Based Discriminative Model
However, lower Riv is usually accompanied as the dependency between adjacent characters 
within a word is no longer directly modeled.



## Character-Based Generative model 
We must regard characters as basic-units to get high Roov.
The remaining problem is how to further raise Riv within the character-based framework.

1. inspect what kinds of character-related clues that the human usually adopts to do word
segmentation,
2. then integrate this clue  into the character-based framework.

### Adhesion and Dependency Between Adjacent Characters
logP(ci|ci-1) for the class of character-bigram within words also tends to have higer value,

###  Proposed Character-Based Generative Model
The generative model should be also applied to handle the dependency within the character-bigram
for reach class(within-words and between-words), which has been shown to be useful.

it regards the character as a unit. Also, since the generative form is adopted, the dependency between
adjacent characters is now directly ( and separately) modeled for each class ( with-words and between-words),
which will give sharper preference when the history of assignment is given.



