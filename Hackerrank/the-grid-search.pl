#Add solution to "The Grid Search" problem in perl

#!/usr/bin/perl

use strict;
use warnings;

# Complete the gridSearch function below.
sub gridSearch {
    my ($G, $P, $R, $C, $r, $c) = @_;
    # Iterate through all the possible rows of big matrix 
    # to see if the first row of small matrix is contained in any of them.
    foreach my $i (0 .. ($R-$r)) {

        my $current_row = $G->[$i];
        
        # check if the first row of small matrix is contained in the current row
        my $found_index = index($current_row, $P->[0]);
        my $local_index = $found_index;
        # print "FOUND_FIRST: row: [$i]; col: [$found_index]\n";
        
        # If the small matrix has only one row then do not check further
        # Return 'YES' to indicate that small matrix is contained in big matrix
        if ($found_index && $r == 1) {
            return 'YES';
        }

        # check all positions where
        # the first row of small matrix is contained in current row
        while ($found_index != -1 && $found_index+$c-1 < $C) {
            my $is_found = 1;

            # Check if all the subsequent rows of small matrix
            # are in the correct position
            # Even if one of the row is not in correct position then it is not found
            foreach my $p_i (1 .. $r-1) {
                if (substr($G->[$i+$p_i], $found_index, $c) ne $P->[$p_i]) {
                    $is_found = 0;
                    last;
                }

                # print "Row: [$p_i]; substr: [".substr($G->[$i+$p_i], $found_index, $c)."] subset_row: [".$P->[$p_i]."]\n";
                # print $G->[$i+$p_i];
                # print "\nfound_index: [$found_index]; c: [$c]\n";
            }
            if ($is_found) {
                return 'YES';
            }
            else {
                # If match is not found for the current index
                # Then check if the next substring can be made out of the current row
                # If yes, then calculate new index of firstrow of small matrix in that substring
                if (length($current_row) <= $local_index+1) {
                    last;
                }
                else {
                    $current_row = substr($current_row, $local_index+1);
                    $local_index = index($current_row, $P->[0]);
                    if ($local_index == -1) {
                        $found_index = -1;
                    }
                    else {
                        $found_index += $local_index+1;
                    }
                }
            }
        }
    }
    return 'NO';
}

open(my $fptr, '>', $ENV{'OUTPUT_PATH'});

my $t = <>;
$t =~ s/\s+$//;

for (my $t_itr = 0; $t_itr < $t; $t_itr++) {
    my $RC = <>;
    $RC =~ s/\s+$//;
    my @RC = split /\s+/, $RC;

    my $R = $RC[0];
    $R =~ s/\s+$//;

    my $C = $RC[1];
    $C =~ s/\s+$//;

    my @G = ();

    for (1..$R) {
        my $G_item = <>;
        chomp($G_item);
        push @G, $G_item;
    }

    my $rc = <>;
    $rc =~ s/\s+$//;
    my @rc = split /\s+/, $rc;

    my $r = $rc[0];
    $r =~ s/\s+$//;

    my $c = $rc[1];
    $c =~ s/\s+$//;

    my @P = ();

    for (1..$r) {
        my $P_item = <>;
        chomp($P_item);
        push @P, $P_item;
    }

    my $result = gridSearch \@G, \@P, $R, $C, $r, $c;

    print $fptr "$result\n";
}

close $fptr;

