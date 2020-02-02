#! /usr/bin/env python

import sys
from optparse import OptionParser
import random


parser = OptionParser()
parser.add_option('-s', '--seed', help='the random seed',
                  default=0, action='store', type='int', dest='seed')
parser.add_option('-n', '--num_questions', help='number of questions',
                  default=5, action='store', type='int', dest='num_questions')
parser.add_option('-m', '--max_value', help='max value',
                  default=128, action='store', type='int', dest='max_value')
parser.add_option('-p', '--pad_length', help='pad hex answers to this length',
                  default=3, action='store', type='int', dest='pad_length')
parser.add_option('-r', help='do hex to decimal', action='store_true',
                  default=False, dest='reverse')
parser.add_option('-c', help='compute answers for me', action='store_true',
                  default=False, dest='solve')

(options, args) = parser.parse_args()

seed = int(options.seed)
num_questions = int(options.num_questions)
max_value = int(options.max_value)
pad_length = int(options.pad_length)
bin_pad_length = pad_length * 4
reverse = options.reverse
solve = options.solve

random.seed(options.seed)

print ''    
print 'Convert the numbers on the left from',
if reverse:
    print 'hex to binary to decimal.'
else:
    print 'decimal to binary to hex.'
print 'Use different random seeds (-s <seed>) to get different problems.'
print 'Specify the number of questions with (-n <number>), and see if you'
print 'are right by having the program solve it for you (-c).'
print ''

if reverse == False:
    print '%7s  %9s    %s' % ('decimal', 'binary', 'hex')
else:
    print '%7s  %9s    %s' % ('hex', 'binary', 'decimal')
for i in range(num_questions):
    v = int(random.random() * max_value)
    answer = '0x%x' % v
    pad_str = '0' * (pad_length - len(answer))

    bin_answer = str(bin(v))[2:]
    bin_pad_str = '0' * (bin_pad_length - len(bin_answer))

    if solve:
        if reverse == False:
            # hex on left
            print '%8s %12s %3s' % (str(v),
                                    bin_pad_str + bin_answer,
                                    pad_str + answer)
        else:
            print '%8s %12s %3s' % (pad_str + answer,
                                    bin_pad_str + bin_answer,
                                    str(v))
    else:
        if reverse == False:
            print '%8s %6s      %3s' % (str(v), '?', '?')
        else:
            print '%8s %6s      %3s' % (pad_str + answer, '?', '?')


    



