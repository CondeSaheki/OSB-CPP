#pragma once
#include "type.h"
#include <vector>
#include <iostream>

namespace nimiat::osu
{

	class file
	{
	private: // type
		class _general
		{
			string AudioFilename;
			integer AudioLeadIn;
			string AudioHash;
			integer PreviewTime;
			integer Countdown;
			string SampleSet;
			decimal StackLeniency;
			integer Mode;
			logical LetterboxInBreaks;
			logical StoryFireInFront;
			logical UseSkinSprites;
			logical AlwaysShowPlayfield;
			string OverlayPosition;
			string SkinPreference;
			logical EpilepsyWarning;
			integer CountdownOffset;
			logical SpecialStyle;
			logical WidescreenStoryboard;
			logical SamplesMatchPlaybackRate;
		};
		class _editor
		{
			std::vector<integer> Bookmarks;
			decimal DistanceSpacing;
			decimal BeatDivisor;
			integer GridSize;
			decimal TimelineZoom;
		};
		class _metadata
		{
			string Title;
			string TitleUnicode;
			string Artist;
			string ArtistUnicode;
			string Creator;
			string Version;
			string Source;
			std::vector<string> Tags;
			integer BeatmapID;
			integer BeatmapSetID;
		};
		class _difficulty
		{
			decimal HPDrainRate;
			decimal CircleSize;
			decimal OverallDifficulty;
			decimal ApproachRate;
			decimal SliderMultiplier;
			decimal SliderTickRate;
		};
		class _events; // ultra sus
		class _timing_point
		{
			integer time; 
			decimal beatLength; 
			integer meter; 
			integer sampleSet; 
			integer sampleIndex; 
			integer volume; 
			logical uninherited;
			integer effects;
		};
		class _colours
		{
			std::vector<rgb> combos;
			rgb SliderTrackOverride;
			rgb SliderBorder;
		};
		class _hitobject
		{
			integer x;
			integer y;
			integer time;
			integer type;
			integer hitSound;
			objectParams;
			hitSample;
		};
	public: // data
		string format;
		_general general;
		_editor editor;
		_metadata metadata;
		_difficulty difficulty;
		// _events events;

		std::vector<_timing_point> timing_points;
		_colours colours;
		std::vector<_hitobject> hitobjects;
	};
	

	string input_file(string path) { return "asd"; }

	void teste()
	{
		string file(input_file("caminho"));

		if (!file.empty())
		{

			// find a regex 
			// cut from str the regex 
			// after all regex cuts check if there is something left 







		}

	
	
	}



}

