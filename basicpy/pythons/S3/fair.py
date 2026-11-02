def max_fair_sequence(arr):
    pos = sorted([x for x in arr if x > 0], reverse=True)
    neg = sorted([x for x in arr if x < 0],reverse=True) 
    def build_sequence(start_with_pos):
        i, j = 0, 0
        turn = 'pos' if start_with_pos else 'neg'
        fair_seq = []

        while i < len(pos) or j < len(neg):
            if turn == 'pos' and i < len(pos):
                fair_seq.append(pos[i])
                i += 1
                turn = 'neg'
            elif turn == 'neg' and j < len(neg):
                fair_seq.append(neg[j])
                j += 1
                turn = 'pos'
            else:
                break

        return sum(fair_seq), fair_seq
    sum_pos, seq_pos = build_sequence(True)
    sum_neg, seq_neg = build_sequence(False)

    if sum_pos > sum_neg:
        return sum_pos, seq_pos
    else:
        return sum_neg, seq_neg
A =[40,-2,10,-100,5,-5,30,1]
total, sequence = max_fair_sequence(A)
print("Fair sequence is =", sequence)
print("Maximum sum is =", total)
      