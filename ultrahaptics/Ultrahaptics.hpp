
#ifndef ULTRAHAPTICS_API_HPP__
#define ULTRAHAPTICS_API_HPP__

#ifndef API_DECORATION_H__
#define API_DECORATION_H__
   #ifdef NO_DECORATION
      #define UH_API_DECORATION
      #define UH_API_CLASS_DECORATION
      #define UH_API_LOCAL_CLASS_DECORATION
   #else
      #ifdef _WIN32
         #ifdef ULTRAFOCUS_LIBRARY_INTERNAL_USE
            #define UH_API_DECORATION __declspec(dllexport)
         #else
            #define UH_API_DECORATION __declspec(dllimport)
         #endif
         #define UH_API_CLASS_DECORATION
         #define UH_API_LOCAL_CLASS_DECORATION
      #else
         #define UH_API_DECORATION
         #define UH_API_CLASS_DECORATION __attribute__((visibility("default")))
         #define UH_API_LOCAL_CLASS_DECORATION __attribute__((visibility("hidden")))
      #endif
   #endif
#endif

#define DEFAULT_CONTROL_POINT_FREQUENCY 125

#define ULTRAFOCUS_VERSION_MAJOR @ULTRAHAPTICS_VERSION_MAJOR@
#define ULTRAFOCUS_VERSION_MINOR @ULTRAHAPTICS_VERSION_MINOR@
#define ULTRAFOCUS_VERSION_REVISION @ULTRAHAPTICS_VERSION_REVISION@

#include <stdio.h>
#include <stddef.h>
#include <math.h>

namespace Ultrahaptics
{
   /** Simple vector class.
    *
    * \brief Implementation of simple 3D vectors */
   class Vector3
   {
      public:
         /** Default constructor. */
         inline Vector3() : x(0.f), y(0.f), z(0.f) {}
         /** Construct a 3D vector with x, y and z components.
          *
          * @param ix The x-coordinate for the new vector
          *
          * @param iy The y-coordinate for the new vector
          *
          * @param iz The z-coordinate for the new vector */
         inline Vector3(float ix, float iy, float iz) : x(ix), y(iy), z(iz) {}
         /** Unary operation of not-negation for vectors.
          *
          * @return The same vector, as not-negation doesn't change the
          * vector */
         inline Vector3 operator+() const
            { return Vector3(*this); }
         /** Binary operation of addition for vectors.
          *
          * @param rhs The right-hand part of the addition
          *
          * @return Sum of the vectors */
         inline Vector3 operator+(const Vector3 &rhs) const
            { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
         /** Binary sum-accumlate operation for vectors.
          *
          * @param rhs The vector to accumlate in this vector
          *
          * @return The sum this vector */
         inline Vector3 &operator+=(const Vector3 &rhs)
            { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
         /** Negation operation for vectors.
          *
          * @return The negated vector */
         inline Vector3 operator-() const
            { return Vector3(-x, -y, -z); }
         /** Binary operation of subtraction for vectors.
          *
          * @param rhs The right-hand part of the subtraction
          *
          * @return Difference of the vectors */
         inline Vector3 operator-(const Vector3 &rhs) const
            { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
         /** Binary subtract-accumlate operation for vectors.
          *
          * @param rhs The vector to accumlate in this vector
          *
          * @return The subtracted this vector */
         inline Vector3 &operator-=(const Vector3 &rhs)
            { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }
         /** Binary scaling operation for vectors.
          *
          * @param scale Scaling factor for the vector
          *
          * @return Scaled vector */
         inline Vector3 operator*(float scale) const
            { return Vector3(scale * x, scale * y, scale * z); }
         /** Binary scale-accumlate operation for vectors.
          *
          * @param scale The scale factor to apply to this vector
          *
          * @return The scaled version of this vector */
         inline Vector3 &operator*=(float scale)
            { x *= scale; y *= scale; z *= scale; return *this; }
         /** Vector scaling by a reciprocal, division by a scaling factor.
          *
          * @param denominator The division to apply to each vector component
          *
          * @return The scaled version of this vector */
         inline Vector3 operator/(float denominator) const
         {
            double rcpdenom = 1. / denominator;
            return (*this) * rcpdenom;
         }
         /** Vector scale-accumulate by a reciprocal, division by a scaling
          * factor.
          *
          * @param denominator The division factor to apply to each component of
          * this vector
          *
          * @return The scaled version of this vector */
         inline Vector3 &operator/=(float denominator)
         {
            double rcpdenom = 1. / denominator;
            (*this) *= rcpdenom;
            return *this;
         }
         /** Vector (cross) product of two vectors.
          *
          * @param rhs The right-hand vector in the cross product calculation
          *
          * @return The vector (cross) product vector */
         inline Vector3 cross(const Vector3 &rhs) const
            { return Vector3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x); }
         /** Scalar (dot) product of two vectors.
          *
          * @param rhs The right-hand vector in the dot-product calculation
          *
          * @return The scalar (dot) product scalar value */
         inline float dot(const Vector3 &rhs) const
            { return x*rhs.x + y*rhs.y + z*rhs.z; }
         /** @return The length of this vector */
         inline float length() const
            { return sqrt(x*x + y*y + z*z); }
         /** @return A normalised version of this vector, does not modify the
          * zero vector. */
         inline Vector3 normalize() const
         {
            double tlength = sqrt(x*x + y*y + z*z);
            double reciprocal_of_length = 1. / tlength;
            return (tlength > 0.) ? ((*this) * ((float)reciprocal_of_length)) : Vector3();
         }
         /** The x-component of the vector */
         float x;
         /** The y-component of the vector */
         float y;
         /** The z-component of the vector */
         float z;
   };

   /** Binary scaling operation for vectors.
    *
    * @param scale Scaling factor for the vector
    *
    * @param rhs The vector to scale
    *
    * @return Scaled vector */
   inline Vector3 operator*(float scale, const Vector3 &rhs)
      { return rhs * scale; }
   
   /** Simple units conversion.
    *
    * \brief Definitions of measures. */
   namespace Units
   {
      /** Millimetres */
      const double mm = 0.001;
      /** Millimetres */
      const double millimetres = 0.001;
      /** Centimetres */
      const double cm = 0.01;
      /** Centimetres */
      const double centimetres = 0.01;
      /** Metres */
      const double m = 1.;
      /** Metres */
      const double metres = 1.;
      /** Hertz */
      const double Hz = 1.;
      /** Hertz */
      const double hertz = 1.;
   }
   
   class ControlPointImplementation;
   
   /** Class defining and describing a control point.
    *
    * \brief Point at which the air is controlled, with position and
    * intensity. */
   class UH_API_CLASS_DECORATION ControlPoint
   {
      public:
         /** Control point constructor that constructs a control point with the
          * specified position and intensity.
          *
          * @param x Control point position in x
          *
          * @param y Control point position in y
          *
          * @param z Control point position in z
          *
          * @param intensity Control point intensity between 0 and 1
          *
          * @param frequency Modulation frequency of this control point */
         UH_API_DECORATION ControlPoint(const float x, const float y, const float z,
            const float intensity, const float frequency = DEFAULT_CONTROL_POINT_FREQUENCY);
         /** Control point constructor that constructs a control point with the
          * specified position and intensity.
          *
          * @param position Control point position
          *
          * @param intensity Control point intensity between 0 and 1
          *
          * @param frequency Modulation frequency of this control point */
         UH_API_DECORATION ControlPoint(const Vector3 &position,
            const float intensity, const float frequency = DEFAULT_CONTROL_POINT_FREQUENCY);
         /** Control point constructor that constructs a control point with the
          * specified position and intensity.
          *
          * @param x Control point position in x
          *
          * @param y Control point position in y
          *
          * @param z Control point position in z
          *
          * @param intensity Control point intensity between 0 and 1
          *
          * @param frequency Modulation frequency of this control point
          *
          * @param phase_angle Carrier phase angle for the control point
          * (usually unset, probably this constructor is not used) */
         UH_API_DECORATION ControlPoint(const float x, const float y, const float z,
            const float intensity, const float frequency, const float phase_angle);
         /** Control point constructor that constructs a control point with the
          * specified position and intensity.
          *
          * @param position Control point position
          *
          * @param intensity Control point intensity between 0 and 1
          *
          * @param frequency Modulation frequency of this control point
          *
          * @param phase_angle Carrier phase angle for the control point
          * (usually unset, probably this constructor is not used) */
         UH_API_DECORATION ControlPoint(const Vector3 &position,
            const float intensity, const float frequency, const float phase_angle);
         /** Control point copy constructor.
          *
          * @param other The other control point to copy */
         UH_API_DECORATION ControlPoint(const ControlPoint &other);
         /** Control point copy assignment operator.
          *
          * @param other The other control point to copy
          *
          * @return Itself */
         UH_API_DECORATION ControlPoint &operator=(const ControlPoint &other);
         /** Control point destructor. */
         UH_API_DECORATION ~ControlPoint();
         /** @return Control point position */
         UH_API_DECORATION Vector3 getPosition() const;
         /** Change control point position.
          *
          * @param position New position vector */
         UH_API_DECORATION void setPosition(const Vector3 &position);
         /** @return Control point intensity */
         UH_API_DECORATION float getIntensity() const;
         /** Change control point intensity.
          *
          * @param intensity New control point intensity between 0 and 1 */
         UH_API_DECORATION void setIntensity(const float intensity);
         /** @return The first or single frequency of this control point. */
         UH_API_DECORATION float getFrequency() const;
         /** Set the frequency of this control point set.
          *
          * @param frequency New control point modulation frequency */
         UH_API_DECORATION void setFrequency(const float frequency);
         /** Set the phase angle.
          *
          * @param phase_angle The phase angle to set this control point as */
         UH_API_DECORATION void setPhaseAngle(const float phase_angle);
         /** Set the control point to use an automatic phase angle. */
         UH_API_DECORATION void autoPhaseAngle();
         /** Get the phase angle.
          *
          * @return Negative if the phase angle is automatic and unset, positive
          * if the phase angle is used. */
         UH_API_DECORATION float getPhaseAngle();

         class UH_API_CLASS_DECORATION FrequencyContainer
         {
            friend class Ultrahaptics::ControlPoint;
            public:
               /** Returns a constant reference to the frequency at this
                * position.
                *
                * @param index The index to get the frequency of
                *
                * @return The frequency at the index */
               UH_API_DECORATION const float &at(const size_t index) const;
               /** Returns a reference to the frequency at this position.
                *
                * @param index The index to get the frequency of
                *
                * @return The frequency at the index */
               UH_API_DECORATION float &at(const size_t index);
               /** @return The number of simultaneous modulation frequencies
                * applied to this point. */
               UH_API_DECORATION size_t count() const;
               /** Add a frequency to the simultaneous modulation frequencies to
                * modulate the control point with.
                *
                * @param frequency The frequency of the modulation to use
                *
                * @return The number of frequencies now assigned to this control
                * point */
               UH_API_DECORATION size_t add(const float frequency);
               /** Clear all the simultaneous modulation frequencies from this
                * control point. */
               UH_API_DECORATION void clear();
            protected:
               /** Internal implementation pointer. */
               ControlPointImplementation *control_point;
         } frequencies;
   };

   class EmitterImplementation;

   /** Class defining an emitter.
    *
    * \brief An emitter to which control points can be sent. */
   class UH_API_CLASS_DECORATION Emitter
   {
      public:
         /** Constructor for the emitter. */
         UH_API_DECORATION Emitter();
         /** Destructor for the emitter. */
         UH_API_DECORATION virtual ~Emitter();
         /** Emitter copy constructor.
          *
          * @param other The other emitter to copy */
         UH_API_DECORATION Emitter(const Emitter &other);
         /** Emitter copy assignment operator.
          *
          * @param other The other emitter to copy
          *
          * @return Itself */
         UH_API_DECORATION Emitter &operator=(const Emitter &other);
         /** Callable initialisation to enable control over the intialisation
          * delay. */
         UH_API_DECORATION virtual void initialize();
         /** @return True if the device is connected */
         UH_API_DECORATION bool isConnected();
         /** Emit a pattern of control points from the device.
          *
          * @param controlpoint Array of control points
          *
          * @param controlpointcount Number of control points */
         UH_API_DECORATION bool update(const ControlPoint *controlpoint, const size_t controlpointcount);
         /** Emit a pattern of control points from the device.
          *
          * @param controlpoint Array of control points
          *
          * @param controlpointcount Number of control points */
         UH_API_DECORATION bool update(const ControlPoint &controlpoint, const size_t controlpointcount = 1);
         /** Stop emitting. */
         UH_API_DECORATION bool stop();
         /** @return Width of the device. */
         UH_API_DECORATION const float arrayWidth();
         /** @return Depth of the device. */
         UH_API_DECORATION const float arrayDepth();
         /** @return Addressable width. */
         UH_API_DECORATION const float interactionSpaceWidth();
         /** @return Addressable height. */
         UH_API_DECORATION const float interactionSpaceHeight();
         /** @return Addressable depth. */
         UH_API_DECORATION const float interactionSpaceDepth();
      protected:
         /** Internal implementation pointer. */
         EmitterImplementation *emitter;
   };
   
   class AlignmentImplementation;
   
   /** Class to abstract and simplify vector conversions between the device
    * space and the space of any tracking system employed.
    *
    * \brief Simplifies management of device space alignment. */
   class UH_API_CLASS_DECORATION Alignment
   {
      public:
         /** Default initialiser. Initialises the alignment to the default
          * setting. */
         UH_API_DECORATION Alignment();
         /** Initialise the alignment helper. Basic initialisation of the device
          * to tracking coordinates transform matrix. The matrix is constructed
          * as: [ x00 x01 x02 x03 ] [ x_d ] [ x_t ] [ x04 x05 x06 x07 ] [ y_d ]
          * = [ y_t ] [ x08 x09 x10 x11 ] [ z_d ] = [ z_t ] [ 0 0 0 1 ] [ 1 ] [
          * 1 ]
          *
          * @param x00 Left-most matrix entry in top row
          *
          * @param x01 Left-centre matrix entry in top row
          *
          * @param x02 Right-centre matrix entry in top row
          *
          * @param x03 Right-most matrix entry in top row
          *
          * @param x04 Left-most matrix entry in second row
          *
          * @param x05 Left-centre matrix entry in second row
          *
          * @param x06 Right-centre matrix entry in second row
          *
          * @param x07 Right-most matrix entry in second row
          *
          * @param x08 Left-most matrix entry in third row
          *
          * @param x09 Left-centre matrix entry in third row
          *
          * @param x10 Right-centre matrix entry in third row
          *
          * @param x11 Right-most matrix entry in third row */
         UH_API_DECORATION Alignment(
            const float x00, const float x01, const float x02, const float x03,
            const float x04, const float x05, const float x06, const float x07,
            const float x08, const float x09, const float x10, const float x11);
         /** Load an alignment from an XML file.
          *
          * @param alignment_load The file to load the alignment configuration
          * from */
         UH_API_DECORATION Alignment(const char *alignment_load);
         /** Copy constructor for alignment.
          *
          * @param other The other instance to copy */
         UH_API_DECORATION Alignment(const Alignment &other);
         /** Copy assignment operator for alignment.
          *
          * @param other The other instance to copy
          *
          * @return Itself */
         UH_API_DECORATION Alignment &operator=(const Alignment &other);
         /** Destuctor */
         UH_API_DECORATION ~Alignment();
         /** Save the alignment to an XML file.
          *
          * @param alignment_save The file to save the alignment configuration
          * to
          *
          * @return True if the save succeeded, false if it did not */
         UH_API_DECORATION bool saveAlignment(const char *alignment_save) const;
         /** Load the alignment from an XML file.
          *
          * @param alignment_load The file to load the alignment configuration
          * from
          *
          * @return True if the load succeeded, false if it did not */
         UH_API_DECORATION bool loadAlignment(const char *alignment_load);
         /** Transform a direction vector from tracking space to device space.
          *
          * @param tracking_direction The direction in tracking space
          *
          * @return The direction in device space */
         UH_API_DECORATION Vector3 fromTrackingDirectionToDeviceDirection(const Vector3 &tracking_direction) const;
         /** Transform a position vector from tracking space to device space.
          *
          * @param tracking_position The position in tracking space
          *
          * @return The position in device space */
         UH_API_DECORATION Vector3 fromTrackingPositionToDevicePosition(const Vector3 &tracking_position) const;
         /** Transform a direction vector from device space to tracking space.
          *
          * @param device_direction The direction in device space
          *
          * @return The direction in tracking space */
         UH_API_DECORATION Vector3 fromDeviceDirectionToTrackingDirection(const Vector3 &device_direction) const;
         /** Transform a position vector from device space to tracking space.
          *
          * @param device_position The position in device space
          *
          * @return The position in tracking space */
         UH_API_DECORATION Vector3 fromDevicePositionToTrackingPosition(const Vector3 &device_position) const;
         /** Put the 4x4 matrix that describes the transformation from tracking
          * space to device space into the array, in row major order.
          *
          * @param output_array The array to put the matrix into. */
         UH_API_DECORATION void fromTrackingToDeviceTransformToArray4x4(float *output_array) const;
         /** Put the 4x4 matrix that describes the transformation from device
          * space to tracking space into the array, in row major order.
          *
          * @param output_array The array to put the matrix into. */
         UH_API_DECORATION void fromDeviceToTrackingTransformToArray4x4(float *output_array) const;
         /** Put the 4x4 matrix that describes the transformation from tracking
          * space to device space into the array, in row major order.
          *
          * @param output_array The array to put the matrix into. */
         UH_API_DECORATION void fromTrackingToDeviceTransformToArray4x4(double *output_array) const;
         /** Put the 4x4 matrix that describes the transformation from device
          * space to tracking space into the array, in row major order.
          *
          * @param output_array The array to put the matrix into. */
         UH_API_DECORATION void fromDeviceToTrackingTransformToArray4x4(double *output_array) const;
      protected:
         /** Internal implmentation pointer. */
         AlignmentImplementation *alignment;
   };
}

#endif
