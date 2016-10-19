llvvAnalysis
==============

General:

	git clone git@github.com:aabdelal/llvvAnalysis.git


Prepare:

	setenv SCRAM_ARCH slc6_amd64_gcc530
	scramv1 project CMSSW CMSSW_8_0_5
	cd CMSSW_8_0_5/src
	cmsenv
	##if you want limit calculation tools merge egamma before clone llvvAnalysis
        ## if not skip steps #N
	git cms-merge-topic ikrav:egm_id_7.4.12_v1    #N
	##
	git clone git@github.com:rjwang/llvvAnalysis.git llvvAnalysis/DMAnalysis #N

	## set up the RooStats-based statistics tools for Higgs PAG
	## https://twiki.cern.ch/twiki/bin/viewauth/CMS/SWGuideHiggsAnalysisCombinedLimit
	git clone https://github.com/cms-analysis/HiggsAnalysis-CombinedLimit.git HiggsAnalysis/CombinedLimit #N
	cd HiggsAnalysis/CombinedLimit #N
	git checkout 74x-root6 #N
	git fetch origin #N
	git checkout v6.0.0 #N
	scramv1 b vclean; scramv1 b # always make a clean build, as scram doesn't always see updates to src/LinkDef.h

	## for CMSSW_7_6_X
	setenv SCRAM_ARCH slc6_amd64_gcc493
	scramv1 project CMSSW CMSSW_7_6_3
	cd CMSSW_7_6_3/src
	cmsenv
	git clone git@github.com:rjwang/llvvAnalysis.git llvvAnalysis/DMAnalysis
