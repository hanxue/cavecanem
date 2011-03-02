AC_DEFUN([NDDS_CHECK],
[
	dnl
	dnl Set up configure script macros
	dnl
	AC_ARG_WITH(ndds,
		[  --with-ndds=<path>     path containing NDDS header and library subdirs],
		[NDDS_lib_check="$with_ndds/lib/i86Linux2.4gcc3.2.2 $with_ndds/lib/i86Linux2.4gcc3.2 $with_ndds/lib/i86Linux2.6gcc3.4.3 $with_ndds/lib/i86Linux2.6gcc4.1.1 $with_ndds/lib/i86Linux2.6gcc4.1.2 $with_ndds/lib/i86Suse10.1gcc4.1.0 $with_ndds/lib/x64Linux2.4gcc3.2.3  $with_ndds/lib/x64Linux2.6gcc3.4.5 $with_ndds/lib/x64Linux2.6gcc4.1.1 $with_ndds/lib/x64Linux2.6gcc4.1.2 $with_ndds/lib/x64Linux2.6gcc4.3.2 $with_ndds/lib/x64Suse10.1gcc4.1.0"
		  NDDS_inc_check="$with_ndds/include $with_ndds/include/ndds"],
		[NDDS_lib_check="$NDDSHOME/lib/i86Linux2.4gcc3.2.2 $NDDSHOME/lib/i86Linux2.4gcc3.2 $NDDSHOME/lib/i86Linux2.6gcc3.4.3 $NDDSHOME/lib/i86Linux2.6gcc4.1.1 $NDDSHOME/lib/i86Linux2.6gcc4.1.2 $NDDSHOME/lib/i86Suse10.1gcc4.1.0 $NDDSHOME/lib/x64Linux2.4gcc3.2.3  $NDDSHOME/lib/x64Linux2.6gcc3.4.5 $NDDSHOME/lib/x64Linux2.6gcc4.1.1 $NDDSHOME/lib/x64Linux2.6gcc4.1.2 $NDDSHOME/lib/x64Linux2.6gcc4.3.2 $NDDSHOME/lib/x64Suse10.1gcc4.1.0"
		  NDDS_inc_check="$NDDSHOME/include $NDDSHOME/include/ndds"])
		  
	dnl
	dnl Look for NDDS library
	dnl
	AC_CACHE_CHECK([for NDDS library location], [ac_cv_ndds_lib],
	[
		for dir in $NDDS_lib_check
		do
			if test -d "$dir" && \
				( test -f "$dir/libnddscd.so" ||
				  test -f "$dir/libnddscored.so" ||
				  test -f "$dir/libnddscore.so" ||
				  test -f "$dir/libnddscorez.a" ||
				  test -f "$dir/libnddscorezd.a" ||
				  test -f "$dir/libnddscppd.so" ||
				  test -f "$dir/libnddscpp.so" ||
				  test -f "$dir/libnddscppz.a" ||
				  test -f "$dir/libnddscppzd.a" ||
				  test -f "$dir/libnddsc.so" ||
				  test -f "$dir/libnddscz.a" ||
				  test -f "$dir/libnddsczd.a" )
			then
				ac_cv_ndds_lib=$dir
				break
			fi
		done

		if test -z "$ac_cv_ndds_lib"
		then
			AC_MSG_ERROR([Didn't find the NDDS library dir in '$NDDS_lib_check'])
		fi

		case "$ac_cv_ndds_lib" in
			/* ) ;;
			* )  AC_MSG_ERROR([The NDDS library directory ($ac_cv_ndds_lib) must be an absolute path.]) ;;
		esac
	])
		  
	AC_SUBST([NDDS_LIB_DIR],[$ac_cv_ndds_lib])

	dnl
	dnl Look for MySQL++ header file directory
	dnl
	AC_CACHE_CHECK([for NDDS include path], [ac_cv_ndds_inc],
	[
		for dir in $NDDS_inc_check
		do
			if test -d "$dir" && (test -f "$dir/ndds_cpp.h" || test -f "$dir/ndds/ndds_cpp.h")
			then
				ac_cv_ndds_inc="-I"$dir" "$ac_cv_ndds_inc
			fi
		done

		if test -z "$ac_cv_ndds_inc"
		then
			AC_MSG_ERROR([Didn't find the NDDS header dir in '$NDDS_inc_check'])
		fi

	])
	
	AC_SUBST([NDDS_INCLUDES],[$ac_cv_ndds_inc])

]) dnl End NDDS_CHECK
		  
