NF{ 
    if ($3 >= 93) { $3 = $3 FS "1.0"; print $0; }
    else if ($3 >= 88) { $3 = $3 FS "1.25"; print $0; }
    else if ($3 >= 85) { $3 = $3 FS "1.5"; print $0; }
    else if ($3 >= 82) { $3 = $3 FS "1.75"; print $0; }
    else if ($3 >= 78) { $3 = $3 FS "2.0"; print $0; }
    else if ($3 >= 74) { $3 = $3 FS "2.25"; print $0; }
    else if ($3 >= 70) { $3 = $3 FS "2.5"; print $0; }
    else if ($3 >= 66) { $3 = $3 FS "2.75"; print $0; }
    else if ($3 >= 60) { $3 = $3 FS "3.0"; print $0; }
    else { $3 = $3 FS "5.0"; print $0 }
}
