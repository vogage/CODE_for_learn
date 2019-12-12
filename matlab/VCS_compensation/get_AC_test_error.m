function xyz_error=get_AC_test_error(AC_element,AC_element_error,AC_test)

    mean_a=(AC_element(1,1)+AC_element(3,1))/2
    mean_c=(AC_element(1,2)+AC_element(2,2))/2
    m=(AC_element(3,1)-AC_element(1,1))/2
    n=(AC_element(2,2)-AC_element(1,2))/2
    xyz_error=zeros(1,3)
    t=(AC_test(2)-mean_c)/n
    s=(AC_test(1)-mean_a)/m
    
    
  for i=1:4
        tj=(AC_element(i,2)-mean_c)/n
        sj=(AC_element(i,1)-mean_a)/m
        Nj=(1+t*tj)*(1+sj*s)/4
        xyz_error=xyz_error+AC_element_error(i,:)*Nj
  end
  