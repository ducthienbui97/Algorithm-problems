\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{saco}[2005/09/22 South African Computer Olympiad]
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{article}}
\ProcessOptions\relax
\LoadClass[twocolumn,a4paper]{article}
\RequirePackage{a4wide,verbatim,fancyhdr,graphics,color,tabularx,array,amsmath,subfigure,pdfpages}
\RequirePackage[all]{xy}
% The following macros should be set with \def, before the
% \documentclass. This approach allows options to be set on the latex
% command line.
%
% \def\place{someplace}
% \def\event{someevent}
% \def\daytitle{Day 1} (optional)
% \def\sponsora{somesponsor, or blank}
% \def\sponsorb{somesponsor, or blank}
% \def\sponsorc{somesponsor, or blank} (appears in centre)
% \def\thedate{somedate}
% For each problem 'prob'
% \def\problocation{/path/to/problem/tree}
% \def\probopname{title}
% \def\probopmaxtime{number}
% \def\probopmaxmemory{string}
% \def\probopsamplescore{number}
% \def\proboprealscore{number}
% \def\probopruns{number}
% \def\probopauthor{name}
% \def\proboptype{data|run|interactive}
% \def\probopdate{date}
% \def\probsourceextensions{\do{.c}\do{.cpp}\do{.etc}}, or leave out entirely
% \def\probinext{.in}, or leave out entirely for 'stdin'
% \def\proboutext{.out}, or leave out entirely for 'stdout'

% Utilities
% Defines #1 to #2 only if #1 is undefined
\newcommand{\providedefault}[2]{%
  \ifx#1\@undefined\gdef#1{#2}\fi}

% A wrapper around \tabularx that first expands the arguments
\newcommand{\begintabularx}[2]{%
  \edef\next{\noexpand\begin{tabularx}{#1}{#2}}%
  \next}

\newtoks\thedoproblems
\thedoproblems{}
\newcommand{\doproblems}{\the\thedoproblems}
\newcount\@time@limit@count

% Options
\providedefault{\thedate}{}
\providedefault{\theplace}{}
\providedefault{\event}{South African Computer Olympiad}
\providedefault{\problem}{\jobname}
\providedefault{\sponsora}{}
\providedefault{\sponsorb}{}
\providedefault{\sponsorc}{}
\providedefault{\sponsord}{}

% Commands to be used from the main file
\newcommand{\problems}{%
  \def\doprob##1{%
    \renewcommand\problem{##1}%
    % determine whether this is a pdf
    \edef\fext{\csname ##1extension\endcsname}%
    \edef\pdfext{pdf}%
    \typeout{\fext\pdfext}%
    \ifx\fext\pdfext%
        \includepdf[pages=-]{\csname ##1location\endcsname/##1.pdf}%
    \else%
        \clearpage
        % Define away some commands, so that we can include files that
        % are also complete LaTeX files
        \renewcommand{\documentclass}[2][]{}%
        \let\realenddocument\enddocument
        \renewenvironment{document}{}{}%
        \input{\csname ##1location\endcsname/##1.tex}%
        \let\enddocument\realenddocument
        \clearpage
    \fi
    }%
  \doproblems}

% Setup of the overview
\def\strip@s\\#1{#1}
\newcommand{\sourc@files}[1]{%
  \expandafter\ifx\csname #1sourceextensions\endcsname\relax
    N/A%
  \else
    \def\do##1{\\#1##1}\let\realbackslash=\\
    \def\\{\let\\=\realbackslash}%
    \csname #1sourceextensions\endcsname
    \let\\=\realbackslash
  \fi}
\newcommand{\in@file}[1]{%
  \expandafter\ifx\csname #1inext\endcsname\relax
    stdin%
  \else
    #1\csname #1inext\endcsname
  \fi}
\newcommand{\out@file}[1]{%
  \expandafter\ifx\csname #1outext\endcsname\relax
    stdout%
  \else
    #1\csname #1outext\endcsname
  \fi}

\newcounter{totalscore}
\newcommand{\overview}{%
  \onecolumn
  \setcounter{totalscore}{0}%
  {\Huge\bfseries\begin{center}Overview\end{center}}\vspace{2cm}%
  {\Large
  \setlength{\extrarowheight}{0.5\baselineskip}%
  \newtoks\t@mplate
  \t@mplate{|c|}%
  \def\doprob##1{\addto@hook{\t@mplate}{>{\centering}X|}}%
  \doproblems
  \begintabularx{0.9\textwidth}{\the\t@mplate}%
  \hline
  %\gdef\doprob##1{& \textbf{\getproboption{##1}{opauthor}{-}}}%
  %\textbf{Author(s)} \doproblems\arraybackslash\\ \hline
  \gdef\doprob##1{& \textbf{##1}}%
  \textbf{Problem} \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \sourc@files{##1}}%
  Source \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \in@file{##1}}%
  Input file \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \out@file{##1}}%
  Output file \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \time@limit{##1}}%
  Time limit \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \memory@limit{##1}}%
  Memory limit \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \getproboption{##1}{opruns}{-}}%
  Number of tests \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \getproboption{##1}{opsamplescore}{-}}%
  Points per test \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \getproboption{##1}{feedback}{-}}%
  Detailed feedback \doproblems \arraybackslash\\ \hline
  \gdef\doprob##1{& \textbf{\getproboption{##1}{oprealscore}{-}}}%
  \textbf{Total points} \doproblems \arraybackslash\\ \hline
  \end{tabularx}%
  \gdef\doprob##1{%
    \addtocounter{totalscore}{\getproboption{##1}{oprealscore}{0}}}%
  \doproblems
  }\par\vspace{2cm}%
  \begin{center}%
  \huge
  The maximum total score is \arabic{totalscore} points.%
  \end{center}%
  \ifx\theurl\@undefined\else\vfill \texttt{\theurl}\fi
  \clearpage\twocolumn}

\newcommand{\addproblem}[3][tex]{%
  \addto@hook{\thedoproblems}{\doprob{#2}}%
  \expandafter\providecommand\csname #2location\endcsname{#3}%
  \expandafter\providecommand\csname #2extension\endcsname{#1}%
}

% Access to options file: problem, name, default
\newcommand{\getproboption}[3]{%
  \expandafter\ifx\csname #1#2\endcsname\relax #3%
  \else \csname #1#2\endcsname\fi}%
\newcommand{\getoption}[2][]{\getproboption{\problem}{#2}{#1}}
\newcommand{\problocation}[1]{%
  \expandafter\ifx\csname #1location\endcsname\relax
    ../../../../problems/#1%
  \else\csname #1location\endcsname\fi}

% Set up handy commands to produce sections
\renewcommand{\maketitle}{%
  {\Huge\bfseries\begin{center}\getoption{opname}\end{center}}%
  \expandafter\ifx\csname \problem opauthor\endcsname\@empty\else
  \begin{center}\getoption{opauthor}\end{center}\fi
}
\newcommand{\try@verbatiminput}[1]{%
  \IfFileExists{#1}{\verbatiminput{#1}}{\texttt{TBA}}}
\newcommand{\sampleinput}{%
  \subsection{Sample input}%
  \begin{samepage}%
  \try@verbatiminput{\problocation{\problem}/data/\problem 0.in}%
  \end{samepage}%
}
\newcommand{\sampleoutput}{%
  \subsection{Sample output}%
  \begin{samepage}%
  \try@verbatiminput{\problocation{\problem}/../../output/problems/\problem/\problem 0.out}%
  \end{samepage}%
}
\newcommand{\inputformat}{%
  \section{Input (\in@file{\problem})}}
\newcommand{\outputformat}{%
  \section{Output (\out@file{\problem})}}
\newcommand{\feedback@runs}[1]{%
  \edef\@testd{#1}%
  \edef\@teste{Yes}%
  \section{Detailed feedback}%
  \ifx\@testd\@teste\relax Detailed feedback is enabled for this problem.%
  \else Detailed feedback is enabled for this problem. You are limited to \@testd \ submissions with detailed feedback.%
  \fi}
\newcommand{\feedback}{%
  \edef\@testa{\getproboption{\problem}{feedback}{0}}%
  \edef\@testb{Yes}%
  \edef\@testc{No}%
  \ifx\@testa\@testb\relax \feedback@runs{\@testa}%
  \else%
    \ifx\@testa\@testc%
    \else \feedback@runs{\@testa}%
    \fi%
  \fi}
% Pass raw time; expands to "1 second" or "X seconds"
\newcommand{\time@limit@seconds}[1]{%
  \edef\@testd{#1}%
  \ifnum 1=\@testd\relax \@testd\ second%
  \else \@testd\ seconds\fi}
\newcommand{\time@limit}[1]{%
  \edef\@testa{\getproboption{#1}{opmaxtime}{0}}%
  \edef\@testb{\getproboption{#1}{optype}{run}}%
  \edef\@testc{data}%
  \ifx\@testb\@testc%
    N/A%
  \else\time@limit@seconds{\@testa}%
  \fi}
\newcommand{\timelimit}{\section{Time limit}\time@limit{\problem}.}
% Usage: \timelimitlang{Python}{10} for 10x multiplier
\newcommand{\timelimitlang}[2]{%
  %\edef\@testb{\getproboption{\problem}{optype}{run}}%
  %\edef\@testc{data}%
  %\ifx\@testb\@testc\relax\else
    %\edef\@testa{\getproboption{\problem}{opmaxtime}{0}}%
    %\@time@limit@count=\@testa
    %\multiply\@time@limit@count by #2%
    \ #1 multiplier: #2. %\time@limit@seconds{\number\@time@limit@count}.%
  %\fi
  }
\newcommand{\memory@limit}[1]{%
  \edef\@testa{\getproboption{#1}{opmaxmemory}{0}}%
  \edef\@testb{\getproboption{#1}{optype}{run}}%
  \edef\@testc{data}%
  \ifx\@testb\@testc%
    N/A%
  \else\@testa%
  \fi}
\newcommand{\problemdate}{\getoption[\thedate]{opdate}}

% Disable section numbering
\let\oldsection\section
\let\oldsubsection\subsection
\def\section{\oldsection*}
\def\subsection{\oldsubsection*}

% Set up fancy layout
\newcommand{\@sponsor}[2]{%
  \ifx#1\@empty\else
    \resizebox{!}{#2}{\includegraphics{#1.png}}%
  \fi}
\newcommand{\@sponsorw}[2]{%
  \ifx#1\@empty\else
    \resizebox{#2}{!}{\includegraphics{#1.png}}%
  \fi}

\addtolength{\headheight}{80pt}
\addtolength{\topmargin}{-2.2cm}
\addtolength{\textwidth}{4cm}
\addtolength{\oddsidemargin}{-2cm}
\addtolength{\evensidemargin}{-2cm}
\lhead{\@sponsor{\sponsora}{80pt}}
\chead{\huge\bfseries
  \event
  \ifx\daytitle\@undefined\else\\ \daytitle\fi}
\rhead{\@sponsor{\sponsorb}{80pt}}
\ifx\sponsord\@empty{%
  \lfoot{\huge \problemdate}%
  \rfoot{\huge \theplace}%
  \ifx\sponsorc\@empty
    \cfoot{}%
  \else
    \cfoot{\raisebox{-20pt}{\@sponsor{\sponsorc}{40pt}}}%
  \fi
\else
  \lfoot{\parbox[c][30pt][t]{0.5\textwidth}{\@sponsorw{\sponsorc}{120pt}}}%
  \cfoot{\huge \problemdate}%
  \rfoot{\parbox[c][30pt][t]{0.5\textwidth}{\raggedleft\@sponsorw{\sponsord}{120pt}}}%
\fi
\renewcommand{\footrulewidth}{0.4pt}
\pagestyle{fancy}
\addtolength{\columnsep}{1cm}
\columnseprule 0.4pt
