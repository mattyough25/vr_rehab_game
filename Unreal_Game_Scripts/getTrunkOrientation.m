
% function [a,R] = getTrunkOrientation(nElbLoc,nHandLoc)
% CALCULATE EULER ANGLES AND ROTATION MATRIX FOR TRUNK
% - uses vectors for elbow and endpoint to fit trunk coordinate system
%   X axis is along the radius/ulna toward hand
%   Y axis point from right to left shoulder
%   Z axis is asumed vertical pointing up as in world coordinate system
% - uses quaternion matrix to find Euler angles
%
% INPUTS ------------------------------------------------------------------
%  nElbLoc <numeric [1, 3]> elbow column vector in meters      
%  nHandLoc <numeric [1, 3]> hand/endpoint column vector in meters    
%
% PROPERTIES --------------------------------------------------------------
%  bPlot    <boolean> plot or not            (default: 0)
%
% OUTPUT ------------------------------------------------------------------
%  a <numeric [3,1]> Rotation angles around X, Y, and Z;
%  R <numeric [3 x 3]> Rotation matrix between the two vectors
%
% NOTE ------------------------------------------------------------------
%   Gimbal Lock problem exists, i.e. getEuler gives a +/- pi results 
%   when abs(a(:,2)) is > 90 deg
%
% EXAMPLE
% nShLoc      = [0,0,100]'/100; % in m
% nElbLoc     = [0,0,50]'/100;  
% nHandLoc    = [30*cos(45*pi/180),30*sin(45*pi/180),50]'/100;  
% [a,R] = getTrunkOrientation(nElbLoc,nHandLoc,'bPlot',1);
%
% Valeriya Gritsenko ©2019

function [a,R] = getTrunkOrientation(nElbLoc,nHandLoc,varargin)

in.bPlot    = false;

if ~isempty(varargin)
   for i = 1:numel(varargin)/2
      in.(varargin{(i-1)*2+1}) = varargin{i*2};
   end
end

% define world coordinate system
vUnitOX         = [1;0;0];
vUnitOY         = [0;1;0];
vUnitOZ         = [0;0;1];

% get trunk coordinate system
vX          = nHandLoc - nElbLoc; % x axis points toward the hend along radius/ulna
vZ          = [0;0;0.5]; % z axis assumed to be vertical

[vUnitX,vUnitY,vUnitZ] = getBasis(vX,vZ,'sAxis','xz','bPlot',in.bPlot);

[a,R] = getEulerZYX(vUnitOX,vUnitOY,vUnitOZ,vUnitX,vUnitY,vUnitZ,'sUnit','deg');